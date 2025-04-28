#include <iostream>
#include <fstream>
#include <vector>

// Main function to open the input file
int main() {
    std::ifstream input("input.txt");

    if (!input) {
        std::cout << "Error: Cannot open input file." << std::endl;
        return 1;
    }

// Read the total resources (A, B, C)
    int totalA, totalB, totalC;
    input >> totalA >> totalB >> totalC;

// Read the number of processes
    int n;
    input >> n;

// Initialize the matrices and vectors
    std::vector<std::vector<int>> allocation(n, std::vector<int>(3));
    std::vector<std::vector<int>> maxNeed(n, std::vector<int>(3));
    std::vector<std::vector<int>> need(n, std::vector<int>(3));
    std::vector<int> available(3);

// Read the Allocation matrix
    for (int i = 0; i < n; ++i){
        input >> allocation[i][0] >> allocation[i][1] >> allocation[i][2];
    }

// Read the Max matrix
    for (int i = 0; i < n; ++i){
        input >> maxNeed[i][0] >> maxNeed[i][1] >> maxNeed[i][2];
    }

// Read the Available vector
    input >> available[0] >> available[1] >> available[2];

// Close input file
    input.close();

// Calculate Need matrix (Need = Max - Allocation)
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < 3; ++j){
            need[i][j] = maxNeed[i][j] - allocation[i][j];
        }
    }

// Initialize finished array and safe sequence
    std::vector<bool> finished(n, false);
    std::vector<int> safeSequence;

// The main loop for Banker's Algorithm
    int count = 0;
    while (count < n) {
        bool found = false;
        for (int i = 0; i < n; ++i) {
            if (!finished[i]) {
                bool canAllocate = true;

                for (int j = 0; j < 3; ++j) {
                    if (need[i][j] > available[j]) {
                        canAllocate = false;
                        break;
                    }
                }

                if (canAllocate) {
                    for (int j = 0; j < 3; ++j){
                        available[j] += allocation[i][j];
                    }
                    safeSequence.push_back(i);
                    finished[i] = true;
                    found = true;
                    ++count;
                }
            }
        }

// Check if no process could be allocated this round, the system is unsafe
        if (!found) {
            std::cout << "System is not in a safe state." << std::endl;
            return 0;
        }
    }

// Print the result and finish
    std::cout << "System is in a safe state.\nSafe sequence is: ";
    for (int i = 0; i < safeSequence.size(); ++i){
        std::cout << "P" << safeSequence[i] << (i == safeSequence.size() - 1 ? "\n" : " -> ");
    }
    return 0;
}
