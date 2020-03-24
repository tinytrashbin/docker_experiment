#include <iostream>
#include <chrono>
#include <assert.h>
#include <fstream>
#include "timer.hpp"

// Create a file in "target" folder. Write O(2^n) bytes of data.
void test_write(int n) {
  const std::string io_folder = "target";
  std::ofstream file(io_folder + "/file_write.txt");
  assert(file);
  for (int i = 0; i < n; i++) {
    int64_t buf_size = 1LL << i;
    for (int64_t j = 0; j < buf_size; j++) {
      file << "(" << i << ", " << j << "), " << std::flush;
    }
    file << std::endl;
  }
  file.close();
}

// Create 2^n files in "target/files_list" folder.
void test_write_files(int n) {
  const std::string io_folder = "target/files_list";
  int64_t num_files = (1LL << n);
  for (int64_t i = 0; i < num_files; i++) {
    std::ofstream file(io_folder + "/file" + std::to_string(i) + ".txt");
    assert(file);
    file << i << "/" << num_files << std::endl;
    file.close();
  }
}


int main() {
  using std::cout;
  using std::endl;
  cout << "Writing to file ... " << endl;
  MicroSecondTimer timer;
  test_write(10);
  int64_t time_taken = timer.GetElapsedTime();
  cout << "Time taken in writing single file = " << time_taken << " micro seconds" << endl;
  cout << "Creating files" << endl;
  timer.Restart();
  test_write_files(12);
  time_taken = timer.GetElapsedTime();
  cout << "Time taken in creating files = " << time_taken << " micro seconds" << endl;
  return 0;
}

