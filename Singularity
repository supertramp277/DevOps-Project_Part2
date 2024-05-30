Bootstrap: docker
From: ubuntu:20.04

%labels
    Author "Yanlong Wang"
    Version "1.0"

%files
    # Copy the entire project from the GitHub workspace into /opt/matrix_mult in the container
    . /opt/matrix_mult

%post
    # Install necessary dependencies
    apt-get update && DEBIAN_FRONTEND=noninteractive apt-get install -y \
        mpich \
        libmpich-dev \
        cmake \
        build-essential \
        git \
        && rm -rf /var/lib/apt/lists/*

    # Navigate to the project directory
    cd /opt/matrix_mult

    # Build the project
    mkdir build && cd build
    cd build
    cmake ..
    make

%test
    TEMP_TEST_DIR=/tmp/test_dir
    mkdir -p $TEMP_TEST_DIR
    cd /opt/matrix_mult/build
    CTEST_OUTPUT_ON_FAILURE=1 CTEST_TEST_OUTPUT_SIZE_PASSED=1024 ctest --output-on-failure -T test --test-dir $TEMP_TEST_DIR

%runscript
    exec /opt/matrix_mult/build/MatrixMultiplication
