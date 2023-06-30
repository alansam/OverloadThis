#include <iostream>
#include <iomanip>
#include <string>
#include <numbers>

using namespace std::literals::string_literals;

/*
 *  MARK: operator""_deg_to_rad()
 *
 *  used as conversion from degrees (input param)
 *  to radians (returned output)
 */
constexpr long double operator""_deg_to_rad(long double deg) {
  long double radians = deg * std::numbers::pi_v<long double> / 180.0;
  return radians;
}

auto deg_to_rad = [](long double deg) -> long double {
  auto radians = deg * std::numbers::pi_v<long double> / 180.0;
  return radians;
};

auto rad_to_deg = [](long double radians) -> long double {
  auto deg = radians / (std::numbers::pi_v<long double> / 180.0);
  return deg;
};

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
              << deg_to_rad(deg)
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
              << rad_to_deg(rdns)
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
              << rad_to_deg(rad)
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

  return 0;
}
