#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <thread>
#include <mutex>

using namespace std;

struct ATMRecord {
    string atmId;
    string city;
    double balance;
    int totalTransactions;
};

unordered_map<string, ATMRecord> atmData;
mutex dataMutex;

ATMRecord parseLine(const string& line) {
    stringstream ss(line);
    string value;

    ATMRecord record;

    getline(ss, record.atmId, ',');      
    getline(ss, value, ',');             
    getline(ss, record.city, ',');       
    getline(ss, value, ',');             

    getline(ss, value, ',');             
    record.balance = stod(value);

    getline(ss, value, ',');
    getline(ss, value, ',');
    getline(ss, value, ',');
    getline(ss, value, ',');

    getline(ss, value, ',');
    record.totalTransactions = stoi(value);

    return record;
}

void processChunk(const vector<string>& lines, int start, int end) {
    for (int i = start; i < end; i++) {
        ATMRecord rec = parseLine(lines[i]);

        lock_guard<mutex> lock(dataMutex);
        atmData.emplace(rec.atmId, rec);
    }
}

int main() {

    // -------- IMPORT DATASET --------
    ifstream file("atm_transactions.csv");  
    // --------------------------------

    if (!file) {
        cout << "Error: Dataset file not found.\n";
        return 1;
    }

    vector<string> lines;
    lines.reserve(40000);

    string line;

    getline(file, line); // skip CSV header

    while (getline(file, line)) {
        lines.emplace_back(line);
    }

    file.close();

    int numThreads = thread::hardware_concurrency();
    if (numThreads == 0) numThreads = 4;

    vector<thread> threads;
    int chunkSize = lines.size() / numThreads;

    for (int i = 0; i < numThreads; i++) {

        int start = i * chunkSize;
        int end = (i == numThreads - 1) ? lines.size() : start + chunkSize;

        threads.emplace_back(processChunk, cref(lines), start, end);
    }

    for (auto& t : threads)
        t.join();

    cout << "Total ATMs loaded: " << atmData.size() << endl;

    while (true) {

        string searchATM;
        cout << "\nEnter ATM ID to search (or 'exit'): ";
        cin >> searchATM;

        if (searchATM == "exit")
            break;

        auto it = atmData.find(searchATM);

        if (it != atmData.end()) {
            cout << "City: " << it->second.city << endl;
            cout << "Balance: " << it->second.balance << endl;
            cout << "Total Transactions: " << it->second.totalTransactions << endl;
        }
        else {
            cout << "ATM not found.\n";
        }
    }

    return 0;
}