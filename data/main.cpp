#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>

int processDataFromFile(const std::string &filename, int iterations) {
    try {
        std::ifstream inputFile(filename);
        if (!inputFile.is_open()) {
            throw std::ifstream::failure("Failed to open file: " + filename);
        }

        std::vector<int> data(iterations);
        for (int &value : data) {
            inputFile >> value;
        }

        // Simulate processing without threading
        int result = std::accumulate(data.begin(), data.end(), 0);

        std::cout << "Finished processing file: " << filename << std::endl;
        return result;
    } catch (const std::ifstream::failure &e) {
        std::cerr << "Encountered an error: " << e.what() << std::endl;
        return 0;  // Return 0 in case of an error
    }
}

int main() {
    // Set seed for random number generation
    std::srand(std::time(0));

    // Number of iterations for each file
    int iterations = 5;

    // Process files sequentially
    int result1 = processDataFromFile("data/source1.txt", iterations);
    int result2 = processDataFromFile("data/source2.txt", iterations);

    // Display the final sum
    int sum = result1 + result2;
    std::cout << "Final Sum: " << sum << std::endl;

    return 0;
}
