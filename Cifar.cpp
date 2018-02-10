/*
 * Cifar.cpp
 *
 *  Created on: Feb 8, 2018
 *      Author: user
 */

#include "Cifar.h"

namespace DeepLearning {

Cifar::Cifar() {
    // TODO Auto-generated constructor stub

}

Cifar::~Cifar() {
    // TODO Auto-generated destructor stub
}

int Cifar::LoadImageAndLable(const string path, vector<vector<MatrixXf>> &images, vector<MatrixXf> &labels){

    FILE  *hFile = NULL;
    hFile = fopen(path.c_str(),"rb");
    if(hFile == NULL){
        DBG_ERROR(("there is no path : %s\n", path.c_str()));
        return -1;
    }

    fseek(hFile, 0L, SEEK_END);
    long size = ftell(hFile);
    fseek(hFile, 0L, SEEK_SET);

    int label_long = 10;
    unsigned int n_rows = 32, n_cols = 32, n_channel = 3;
    unsigned long count = size / (32 * 32 * 3 + 1);


    int ret = 0;
    for(unsigned int i = 0; i < count; ++i){

        // read class
        unsigned char index = 0;
        ret = fread((unsigned char*)&index, sizeof(index), 1, hFile);
        if(0 == ret){
           return -1;
        }

        MatrixXf label = MatrixXf::Zero(label_long, 1);
        label((unsigned int)index, 0) = 1.0f;

        labels.push_back(label);

        // read image
        vector<MatrixXf> image;
        for(unsigned int j = 0; j < n_channel; ++j){
            MatrixXf channel = MatrixXf::Zero(n_rows, n_cols);
            for(unsigned int m = 0; m < n_rows; ++m){
                for(unsigned int n = 0; n < n_cols; ++n){
                    unsigned char pixel = 0;
                    ret = fread((unsigned char*) &pixel, sizeof(pixel), 1, hFile);
                    if(0 == ret){
                        return -1;
                    }
                    channel(m, n) = (float)pixel/255.0;
                }
            }
            image.push_back(channel);
        }

        images.push_back(image);
    }

    return 0;
}

} /* namespace DeepLearning */
