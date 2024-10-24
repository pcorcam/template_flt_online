/*
////////////////////////////
//** UTILS HEADER FILE ** //
////////////////////////////

This file defines some utils that are used in the template fitting code.
*/

#ifndef UTILS
#define UTILS

#include <eigen3/Eigen/Dense>

/*
---------
FUNCTIONS
---------
*/

Eigen::ArrayXf correlate(const Eigen::ArrayXf& arr1,
                         const Eigen::ArrayXf& arr2,
                         const bool& norm=false);

float rms(const Eigen::ArrayXf& arr);

Eigen::ArrayXf normalize(const Eigen::ArrayXf& arr);

# endif // UTILS