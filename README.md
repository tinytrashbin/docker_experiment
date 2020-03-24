
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

