/**********************************************************************************************************************
This file is part of the Control Toolbox (https://github.com/ethz-adrl/control-toolbox), copyright by ETH Zurich.
Licensed under the BSD-2 license (see LICENSE file in main directory)
**********************************************************************************************************************/

#pragma once

#include <ct/core/math/Derivatives.h>

namespace ct {
namespace NS1 {
namespace NS2 {

class DERIVATIVE_NAME : public core::Derivatives<IN_DIM, OUT_DIM, double>
{
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW

    typedef Eigen::Matrix<double, IN_DIM, IN_DIM> HES_TYPE;
    typedef Eigen::Matrix<double, IN_DIM, 1> X_TYPE;

    DERIVATIVE_NAME()
    {
        hessian_.setZero();
        v_.fill(0.0);
    };

    DERIVATIVE_NAME(const DERIVATIVE_NAME& other)
    {
        hessian_.setZero();
        v_.fill(0.0);
    }

    virtual ~DERIVATIVE_NAME(){};

    DERIVATIVE_NAME* clone() const override { return new DERIVATIVE_NAME(*this); }
    HES_TYPE hessian(const Eigen::VectorXd& x_in, const Eigen::VectorXd& w_in) override;

private:
    HES_TYPE hessian_;
    std::array<double, MAX_COUNT> v_;
};

}  // namespace NS2
}  // namespace NS1
}  // namespace ct
