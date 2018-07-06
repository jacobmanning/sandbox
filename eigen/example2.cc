#include <iostream>
#include <Eigen/Dense>

void size_at_run_time() {
    auto m = (Eigen::MatrixXd::Random(3, 3) +
              Eigen::MatrixXd::Constant(3, 3, 1.2)) * 50;
    std::cout << "m = " << m << std::endl;

    auto v = Eigen::VectorXd(3);
    v << 1, 2, 3;

    std::cout << "m * v = " << std::endl
              << m * v << std::endl;
}

void size_at_compile_time() {
    auto m = (Eigen::Matrix3d::Random() +
              Eigen::Matrix3d::Constant(1.2)) * 50;
    std::cout << "m = " << m << std::endl;

    auto v = Eigen::Vector3d{1, 2, 3};

    std::cout << "m * v = " << std::endl
              << m * v << std::endl;
}

int main() {
    std::cout << "Size at run time:" << std::endl;
    size_at_run_time();

    std::cout << std::endl;

    std::cout << "Size at compile time:" << std::endl;
    size_at_compile_time();
}
