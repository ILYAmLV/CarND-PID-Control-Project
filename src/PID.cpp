#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_init, double Ki_init, double Kd_init) {
	Kp = Kp_init;
	Ki = Ki_init;
	Kd = Kd_init;

	p_error = 0;
	i_error = 0;
	d_error = 0;
}
// ***************************** Setup the PID variables **********************************************

void PID::UpdateError(double cte) {

	d_error = cte - p_error;
	p_error = cte;
	i_error += cte;
	
}
// ******************* Equations for the Update Error Class were sourced from here **************************
// https://medium.com/towards-data-science/tuning-pid-controller-parameters-with-backpropagation-c42c6f80d3cd

double PID::TotalError() {
	return -Kp * p_error - Ki * i_error - Kd * d_error;
}
// ******************** Equations for the Total Error Class were sourced from here *************************
// https://medium.com/towards-data-science/tuning-pid-controller-parameters-with-backpropagation-c42c6f80d3cd
