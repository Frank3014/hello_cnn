/*
 * Cifar.h
 *
 *  Created on: Feb 8, 2018
 *      Author: user
 */

#ifndef CIFAR_H_
#define CIFAR_H_

#include <vector>
#include <Eigen/Dense>

#include "DebugPrint.h"

using namespace std;
using namespace Eigen;

namespace DeepLearning {

class Cifar {
public:
    Cifar();
    virtual ~Cifar();

    static int LoadImageAndLable(const string path, vector<vector<MatrixXf>> &images, vector<MatrixXf> &labels);
};

} /* namespace DeepLearning */

#endif /* CIFAR_H_ */
