# hello_cnn
1. introduce
    This is a simple CNN implemented in c++.

2. development environment
    Ubuntu 16.04
    gcc 5.4.0

3. dependent libraries
    eigen3 : for matrix operation
    OpenCV-3.2.0 : for debug (convert the results of convolution and pooling to images)

4. dataset
    mnist : http://yann.lecun.com/exdb/mnist/
    CIFAR-10 : https://www.cs.toronto.edu/~kriz/cifar.html

5. compile and run
    cmake .
    make
    ./cnn_test

6. note
    the dataset in not included in this project.
    please download it by yourself, and modify the path in source code.
    the hyperparameters for cifar dataset need to be adjusted.
