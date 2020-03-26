## Performance Overhead due to Docker on MacOS


Introduction
---------------

In this experiment we are trying to understand the run time latency of a C++ program when it’s executed in MacOS natively vs CentOS Docker container with MacOS host.

We have two programs :
1. source/compute.cpp - A C++ program doing heavy computation and no disk IO.
2. source/io.cpp - A C++ program doing heavy file IO operations and negligible computation. It has two parts:
  a.    WriteSingleFile : It writes big chuck of data in a single file (200 KB data).
  b.    CreateMultipleFiles : It creates thousands of new files with minimal text in each file (Total 4096 files).

Results
---------------

|                                          | compute.cpp | io.cpp::WriteSingleFile | io.cpp::CreateMultipleFiles |
|------------------------------------------|-------------|-------------------------|-----------------------------|
| MacOS Native                             | 3767.127 ms | 118.822 ms              | 691.242 ms                  |
| CentOS docker on MacOS machine           | 985.137 ms  | 2882.890 ms             | 8619.886 ms                 |
| CentOS native                            | 2635.857 ms | 37.643 ms               | 163.822 ms                  |
| CentOS docker without mounting directory | 951.297 ms  | 48.117 ms               | 145.776 ms                  |





Create folders:
---------------

`mkdir -p build target target/files_list`


Build docker:
---------------

`docker build -t perf_test .`


Run docker:
---------------


`docker run -v $(pwd)/target:/app/target perf_test`


Native:
---------------


`g++ source/compute.cpp -O3 -o build/compute && ./build/compute`

`g++ source/io.cpp -O3 -o build/io && ./build/io`

