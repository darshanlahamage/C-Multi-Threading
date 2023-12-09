#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <mutex>  // Include the <mutex> header first
#include <atomic>
#include <ctime>

std::atomic<int> sum(0);
std::mutex sumMutex;  // Declare the mutex

void processDataFromFile(int threadId, const std::string& filename, int iterations) {
    try {
        std::ifstream inputFile(filename);
        if (!inputFile.is_open()) {
            throw std::ifstream::failure("Failed to open file: " + filename);
        }

        std::vector<int> data(iterations);
        for (int& value : data) {
            inputFile >> value;
        }

        // Simulate processing without threading
        int result = std::accumulate(data.begin(), data.end(), 0);

        // Use mutex to protect shared sum
        std::lock_guard<std::mutex> lock(sumMutex);
        sum += result;

        std::cout << "Thread " << threadId << " finished processing file: " << filename << std::endl;
    } catch (const std::ifstream::failure& e) {
        std::cerr << "Thread " << threadId << " encountered an error: " << e.what() << std::endl;
    }
}

int main() {
    // Set seed for random number generation
    std::srand(static_cast<unsigned int>(time(nullptr)));

    // Number of iterations for each file
    int iterations = 5;

    // Process files sequentially
    processDataFromFile(1, "data/source_1.txt", iterations);
    processDataFromFile(2, "data/source_2.txt", iterations);

    // Display the final sum
    std::cout << "Final Sum: " << sum << std::endl;

    return 0;
}
