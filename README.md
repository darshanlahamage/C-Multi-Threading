# Multithreaded C/C++ Application

## Introduction

This C++ application is designed to efficiently process data concurrently using multiple threads. The key features of the application include:

- **Multithreading:** The application utilizes at least two threads to process data in parallel.
- **Data Processing:** Simulates data input from multiple sources (files) and processes this data concurrently.
- **Synchronization:** Uses both atomic operations and standard mutexes for synchronization to ensure data integrity and avoid race conditions.
- **Error Handling:** Implements proper error handling and reporting mechanisms.
- **Performance:** Optimizes code to achieve efficient multithreading and processing.

## Instructions

### Prerequisites

- Windows operating system (due to the use of Windows-specific API functions).
- C++ compiler that supports the required features.

### Compilation

1. Open a terminal or command prompt.

2. Navigate to the directory containing the source code.

3. Compile the code using the following command:

    ```bash
    g++ -o my_program main.cpp -std=c++11
    ```

   Note: Ensure that the necessary development tools are installed, including a compatible C++ compiler.

### Execution

4. Run the compiled program:

    ```bash
    ./my_program
    ```

   This will execute the program, and the output will be displayed in the console.

## Design Choices

### Threading Mechanism

The application uses both atomic operations (`std::atomic`) and standard mutex (`std::mutex`) for synchronization. Atomic operations are used for the shared `sum` variable, while the mutex is employed to protect the critical section during sum updates.

### Data Processing

Data is read from two files (`data/source_1.txt` and `data/source_2.txt`). The program simulates data processing by reading integers from these files and calculating the sum concurrently.

### Synchronization

Synchronization is achieved using a combination of atomic operations and standard mutexes. Atomic operations ensure atomic updates to the shared `sum` variable, while the standard mutex (`std::mutex`) protects the critical section during sum updates in the `processDataFromFile` function.

### Error Handling

Error handling is implemented for file opening failures using the `std::ifstream::failure` exception. Any errors encountered during file processing are reported to the standard error stream.

### Performance Optimization

The use of atomic operations and standard mutexes helps achieve synchronization, ensuring data integrity and preventing race conditions in a multithreaded environment.
