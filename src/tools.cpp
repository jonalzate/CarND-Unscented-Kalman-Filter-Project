#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {

  //========================== Calculate the RMSE ===============================
  VectorXd rmse(4);
	rmse << 0,0,0,0;

	// Check estimation vector size is not zero and estimation vector size
	// should equal ground truth vector size
	if(estimations.size() != ground_truth.size() || estimations.size() == 0)
	{
	    cout << "estimations vector is zero and size not equal to ground truth" << endl;
	    return rmse;
	}

	// Accumulate squared residuals
	for(unsigned int i = 0; i < estimations.size(); ++i)
	{
	    // Calculate residual
        VectorXd residual = estimations[i] - ground_truth[i];

        residual = residual.array() * residual.array();

        rmse += residual;
	}

	// Calculate the mean
	rmse = rmse / estimations.size();

	// Calculate the squared root
	rmse = rmse.array().sqrt();

	// Return the result
	return rmse;
}
