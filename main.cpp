#include <iostream>
#include <iomanip>
#include <string>
#include <numbers>

using namespace std::literals::string_literals;

namespace cvt::angular::angular_literals {

/*
 *  MARK: operator""_deg_to_rad()
 *
 *  used as conversion from degrees (input param)
 *  to radians (returned output)
 */
constexpr long double operator""_deg_to_rad(long double deg) {
  long double radians = deg * std::numbers::pi_v<long double> / 180.0l;
  return radians;
}

/*
 *  MARK: operator""_reg_to_deg()
 *
 *  used as conversion from radians (input param)
 *  to degrees (returned output)
 */
constexpr long double operator""_reg_to_deg(long double radians) {
  long double degrees = radians / (std::numbers::pi_v<long double> / 180.0l);
  return degrees;
};

} /* namespace cvt::angular::angular_literals */

namespace cvt::temp::temp_literals {
/*
 *  MARK: operator""_C_to_F()
 *
 *  used as conversion from Centigrade to Fahrenheit
 */
constexpr long double operator""_C_to_F(long double cel) {
  return (cel * 1.8l) + 32.0l;
}

/*
 *  MARK: operator""_F_to_C()
 *
 *  used as conversion from Fahrenheit to Centigrade
 */
constexpr long double operator""_F_to_C(long double far) {
  return (far - 32.0l) / 1.8l;
}

} /*namespace cvt::temp::temp_literals */

namespace cvt::si::si_literals {
/*
 *  MARK: operator""_m(long double val)
 *
 *  Metres - base (10^1)
 */
long constexpr double operator""_m(long double val) {
  return val;
}

/*
 *  MARK: operator""_m(long long)
 *
 *  Metres - base (10^1)
 */
long constexpr double operator""_m(unsigned long long val) {
  return static_cast<long double>(val);
}

/*
 *  MARK: operator""_km(long double)
 *
 *  Metres - kilometres (10^3)
 */
long constexpr double operator""_km(long double val) {
  return val * 1'000.0l;
}

/*
 *  MARK: operator""_km(long long)
 *
 *  Metres - kilometres (10^3)
 */
long constexpr double operator""_km(unsigned long long val) {
  return static_cast<long double>(val) * 1'000.0l;
}

/*
 *  MARK: operator""_mm(long double)
 *
 *  Metres - millimetres (10^-3)
 */
long constexpr double operator""_mm(long double val) {
  return val / 1'000.0l;
}

/*
 *  MARK: operator""_mm(long long)
 *
 *  Metres - millimetres (10^-3)
 */
long constexpr double operator""_mm(unsigned long long val) {
  return static_cast<long double>(val) / 1'000.0l;
}

} /* namespace cvt::si::si_literals */

namespace cvt::angular {
auto deg_to_rad = [](long double deg) -> long double {
  auto radians = deg * std::numbers::pi_v<long double> / 180.0l;
  return radians;
};

auto rad_to_deg = [](long double radians) -> long double {
  auto deg = radians / (std::numbers::pi_v<long double> / 180.0l);
  return deg;
};

} /* namespace cvt::angular */

namespace cvt::temp {
auto cel_to_far = [](long double cel) -> long double {
  return (cel * 1.8l) + 32.0l;
};

auto far_to_cel = [](long double far) -> long double {
  return (far - 32.0l) / 1.8l;
};

} /* namespace cvt::temp */

using namespace cvt::angular::angular_literals;
using namespace cvt::temp::temp_literals;
using namespace cvt::si::si_literals;

/*
 *  MARK: main()
 */
int main() {
  std::cout << std::fixed;
  for (auto deg { 0.0l }; deg <= 360.0l; deg += 7.5l) {
    std::cout << std::setw(10)
              << std::setprecision(1)
              << deg
              << "\u00b0 ="s
              << std::setprecision(6)
              << std::setw(10)
              << cvt::angular::deg_to_rad(deg)
              << " radians."s
              << '\n';
  }
  std::cout << std::endl;

  for (auto fctr { 0.0l }; fctr <= 4.0l; fctr += 0.25l) {
    auto rdns = std::numbers::pi_v<long double> * fctr / 2;
    std::cout << std::setw(10)
              << std::setprecision(6)
              << rdns
              << " radians ["s
              << std::setprecision(2)
              << std::setw(4)
              << fctr
              << "\u22c5\u03c0] ="s
              << std::setprecision(1)
              << std::setw(10)
              << cvt::angular::rad_to_deg(rdns)
              << "\u00b0."s
              << '\n';
  }
  std::cout << std::endl;

  for (auto rad { 0.0l }; rad < 6.75l; rad += 0.25l) {
    std::cout << std::setw(10)
              << std::setprecision(6)
              << rad
              << " radians ="s
              << std::setprecision(2)
              << std::setw(10)
              << cvt::angular::rad_to_deg(rad)
              << "\u00b0."s
              << '\n';
  }
  std::cout << std::endl;

  std::cout << std::setprecision(6);

  std::cout << "    0\u00b0 ="s << std::setw(10)
            <<   0._deg_to_rad << " radians."s << '\n';
  std::cout << "   30\u00b0 ="s << std::setw(10)
            <<  30._deg_to_rad << " radians."s << '\n';
  std::cout << "   45\u00b0 ="s << std::setw(10)
            <<  45._deg_to_rad << " radians."s << '\n';
  std::cout << "   60\u00b0 ="s << std::setw(10)
            <<  60._deg_to_rad << " radians."s << '\n';
  std::cout << "   90\u00b0 ="s << std::setw(10)
            <<  90._deg_to_rad << " radians."s << '\n';
  std::cout << "  120\u00b0 ="s << std::setw(10)
            << 120._deg_to_rad << " radians."s << '\n';
  std::cout << "  135\u00b0 ="s << std::setw(10)
            << 135._deg_to_rad << " radians."s << '\n';
  std::cout << "  150\u00b0 ="s << std::setw(10)
            << 150._deg_to_rad << " radians."s << '\n';
  std::cout << "  180\u00b0 ="s << std::setw(10)
            << 180._deg_to_rad << " radians."s << '\n';
  std::cout << "  210\u00b0 ="s << std::setw(10)
            << 210._deg_to_rad << " radians."s << '\n';
  std::cout << "  225\u00b0 ="s << std::setw(10)
            << 225._deg_to_rad << " radians."s << '\n';
  std::cout << "  270\u00b0 ="s << std::setw(10)
            << 270._deg_to_rad << " radians."s << '\n';
  std::cout << "  300\u00b0 ="s << std::setw(10)
            << 300._deg_to_rad << " radians."s << '\n';
  std::cout << "  315\u00b0 ="s << std::setw(10)
            << 315._deg_to_rad << " radians."s << '\n';
  std::cout << "  330\u00b0 ="s << std::setw(10)
            << 330._deg_to_rad << " radians."s << '\n';
  std::cout << "  360\u00b0 ="s << std::setw(10)
            << 360._deg_to_rad << " radians."s << '\n';
  std::cout << std::endl;

  std::cout << "  0.0 radian ="s << std::setw(10)
            << 0.0_reg_to_deg << "\u00b0."s << '\n';
  std::cout << "  0.5 radian ="s << std::setw(10)
            << 0.5_reg_to_deg << "\u00b0."s << '\n';
  std::cout << "  1.0 radian ="s << std::setw(10)
            << 1.0_reg_to_deg << "\u00b0."s << '\n';
  std::cout << "  1.5 radian ="s << std::setw(10)
            << 1.5_reg_to_deg << "\u00b0."s << '\n';
  std::cout << "  π/2 radian ="s << std::setw(10)
            << 1.57079632679_reg_to_deg << "\u00b0."s << '\n';
  std::cout << "  2.0 radian ="s << std::setw(10)
            << 2.0_reg_to_deg << "\u00b0."s << '\n';
  std::cout << "  2.5 radian ="s << std::setw(10)
            << 2.5_reg_to_deg << "\u00b0."s << '\n';
  std::cout << "  3.0 radian ="s << std::setw(10)
            << 3.0_reg_to_deg << "\u00b0."s << '\n';
  std::cout << "    π radian ="s << std::setw(10)
            << 3.14159265359_reg_to_deg << "\u00b0."s << '\n';
  std::cout << "  3.5 radian ="s << std::setw(10)
            << 3.5_reg_to_deg << "\u00b0."s << '\n';
  std::cout << "  4.0 radian ="s << std::setw(10)
            << 4.0_reg_to_deg << "\u00b0."s << '\n';
  std::cout << "  4.5 radian ="s << std::setw(10)
            << 4.0_reg_to_deg << "\u00b0."s << '\n';
  std::cout << " 3π/2 radian ="s << std::setw(10)
            << 4.71238898038_reg_to_deg << "\u00b0."s << '\n';
  std::cout << "  5.0 radian ="s << std::setw(10)
            << 5.0_reg_to_deg << "\u00b0."s << '\n';
  std::cout << "  5.5 radian ="s << std::setw(10)
            << 5.5_reg_to_deg << "\u00b0."s << '\n';
  std::cout << "  6.0 radian ="s << std::setw(10)
            << 6.0_reg_to_deg << "\u00b0."s << '\n';
  std::cout << "   2π radian ="s << std::setw(10)
            << 6.28318530718_reg_to_deg << "\u00b0."s << '\n';
  std::cout << "  6.5 radian ="s << std::setw(10)
            << 6.5_reg_to_deg << "\u00b0."s << '\n';
  std::cout << std::endl;

  std::cout << std::setprecision(2);
  std::cout << "  -40\u00b0C = "
            << std::setw(7) << cvt::temp::cel_to_far(-40.0l)
            << "\u00b0F\n";
  std::cout << "    0\u00b0C = "
            << std::setw(7) << cvt::temp::cel_to_far(  0.0l)
            << "\u00b0F\n";
  std::cout << "   40\u00b0C = "
            << std::setw(7) << cvt::temp::cel_to_far( 40.0l)
            << "\u00b0F\n";
  std::cout << "   50\u00b0C = "
            << std::setw(7) << cvt::temp::cel_to_far( 50.0l)
            << "\u00b0F\n";
  std::cout << "  100\u00b0C = "
            << std::setw(7) << cvt::temp::cel_to_far(100.0l)
            << "\u00b0F\n";
  std::cout << std::endl;
  std::cout << "  -40\u00b0F = "
            << std::setw(7) << cvt::temp::far_to_cel(-40.0l)
            << "\u00b0C\n";
  std::cout << "    0\u00b0F = "
            << std::setw(7) << cvt::temp::far_to_cel(  0.0l)
            << "\u00b0C\n";
  std::cout << "   32\u00b0F = "
            << std::setw(7) << cvt::temp::far_to_cel( 32.0l)
            << "\u00b0C\n";
  std::cout << "   40\u00b0F = "
            << std::setw(7) << cvt::temp::far_to_cel( 40.0l)
            << "\u00b0C\n";
  std::cout << "  106\u00b0F = "
            << std::setw(7) << cvt::temp::far_to_cel(106.0l)
            << "\u00b0C\n";
  std::cout << "  212\u00b0F = "
            << std::setw(7) << cvt::temp::far_to_cel(212.0l)
            << "\u00b0C\n";
  std::cout << std::endl;

  std::cout << "    0\u00b0C = "
            << std::setw(7) <<   0.0_C_to_F
            << "\u00b0F\n";
  std::cout << "   40\u00b0C = "
            << std::setw(7) <<  40.0_C_to_F
            << "\u00b0F\n";
  std::cout << "   50\u00b0C = "
            << std::setw(7) <<  50.0_C_to_F
            << "\u00b0F\n";
  std::cout << "  100\u00b0C = "
            << std::setw(7) << 100.0_C_to_F
            << "\u00b0F\n";
  std::cout << std::endl;
  std::cout << "    0\u00b0F = "
            << std::setw(7) <<   0.0_F_to_C
            << "\u00b0C\n";
  std::cout << "   32\u00b0F = "
            << std::setw(7) <<  32.0_F_to_C
            << "\u00b0C\n";
  std::cout << "   40\u00b0F = "
            << std::setw(7) <<  40.0_F_to_C
            << "\u00b0C\n";
  std::cout << "  106\u00b0F = "
            << std::setw(7) << 106.0_F_to_C
            << "\u00b0C\n";
  std::cout << "  212\u00b0F = "
            << std::setw(7) << 212.0_F_to_C
            << "\u00b0C\n";
  std::cout << std::endl;

  std::cout << std::setprecision(3);
  std::cout << " 1,000.5  m =" << std::setw(10)
            <<  1'000.5_m << '\n';
  std::cout << "   1,000  m =" << std::setw(10)
            <<    1'000_m << '\n';
  std::cout << "-1,000.5  m =" << std::setw(10)
            << -1'000.5_m << '\n';

  std::cout << " 1,000.0 mm =" << std::setw(10)
            <<  1'000.0_mm << '\n';
  std::cout << "   1,000 mm =" << std::setw(10)
            <<    1'000_mm << '\n';
  std::cout << "-1,000.0 mm =" << std::setw(10)
            << -1'000.0_mm << '\n';

  std::cout << "    10.5 km =" << std::setw(10)
            <<     10.5_km << '\n';
  std::cout << "      10 km =" << std::setw(10)
            <<       10_km << '\n';
  std::cout << "   -10.5 km =" << std::setw(10)
            <<    -10.5_km << '\n';

  auto mk = 100.8_m + 2_km + 150_mm;
  std::cout << "100.8 m + 2 km + 150 mm =" << std::setw(10)
            <<          mk << '\n';
  std::cout << std::endl;

  return 0;
}
