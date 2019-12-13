#include <Eigen/Dense>
#include <iostream>

void size_at_run_time()
{
  auto m = (Eigen::MatrixXd::Random(3, 3) + Eigen::MatrixXd::Constant(3, 3, 1.2)) * 50;
  std::cout << "m = " << m << '\n';

  auto v = Eigen::VectorXd(3);
  v << 1, 2, 3;

  std::cout << "m * v = " << '\n' << m * v << '\n';
}

void size_at_compile_time()
{
  auto m = (Eigen::Matrix3d::Random() + Eigen::Matrix3d::Constant(1.2)) * 50;
  std::cout << "m = " << m << '\n';

  auto v = Eigen::Vector3d{1, 2, 3};

  std::cout << "m * v = " << '\n' << m * v << '\n';
}

int main()
{
  std::cout << "Size at run time:" << '\n';
  size_at_run_time();

  std::cout << '\n';

  std::cout << "Size at compile time:" << '\n';
  size_at_compile_time();
}
