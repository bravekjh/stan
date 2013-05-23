#include <stdexcept>
#include <stan/math/matrix/rank.hpp>
#include <gtest/gtest.h>

template <typename T>
void test_rank() {
  using stan::math::rank;

  T c(1);
  c[0] = 1.7;
  EXPECT_EQ( rank(c,1) , 0 );
  EXPECT_THROW( rank(c,0), std::out_of_range);
  EXPECT_THROW( rank(c,2), std::out_of_range);

  T e(2);
  e[0] = 5.9;  e[1] = -1.2;
  EXPECT_EQ( rank(e,1) , 1 );
  EXPECT_EQ( rank(e,2) , 0 );
  EXPECT_THROW( rank(e,0), std::out_of_range);
  EXPECT_THROW( rank(e,3), std::out_of_range);

  T g(3);
  g[0] = 5.9;  g[1] = -1.2;   g[2] = 192.13456;
  EXPECT_EQ( rank(g,1) , 1 );
  EXPECT_EQ( rank(g,2) , 0 );
  EXPECT_EQ( rank(g,3) , 2 );
  EXPECT_THROW( rank(g,0), std::out_of_range);
  EXPECT_THROW( rank(g,4), std::out_of_range);
  
  T z;
  EXPECT_THROW( rank(z,0), std::out_of_range);
  EXPECT_THROW( rank(z,1), std::out_of_range);
  EXPECT_THROW( rank(z,2), std::out_of_range);  
}

TEST(MathMatrix,rank) {
  using stan::math::rank;
  
  test_rank<std::vector<int> >();
  test_rank<std::vector<double> >();
  test_rank<Eigen::Matrix<double,Eigen::Dynamic,1> >();
  test_rank<Eigen::Matrix<double,1,Eigen::Dynamic> >();
}