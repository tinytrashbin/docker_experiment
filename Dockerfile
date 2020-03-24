FROM centos:7
FROM gcc:9

WORKDIR /app

RUN mkdir -p build
RUN mkdir -p source
RUN mkdir -p target
RUN mkdir -p target/files_list

ADD source/compute.cpp source/compute.cpp
ADD source/timer.hpp source/timer.hpp
ADD source/io.cpp source/io.cpp

RUN g++ source/compute.cpp -O3 -o build/compute
RUN g++ source/io.cpp -O3 -o build/io

CMD ["./build/io"]
# CMD ["./build/compute"]
