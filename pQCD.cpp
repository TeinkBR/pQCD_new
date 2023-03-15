#include "pQCD.hpp"
#include <cmath>

pQCD::pQCD(double X) : X(X) {}

double pQCD::constraints(double a, double b, double c, double d, double e) const {
    return a + b + c + d + e;
}

double pQCD::number_density(double T) const {
    double x = std::log(T / 0.154) / std::log(10);
    double y = 1.39876 - 0.230984 * x + 0.0114343 * std::pow(x, 2) - 0.000349431 * std::pow(x, 3);
    double n = std::pow(10, y);
    return n;
}

double pQCD::edens(double T) const {
    double x = std::log(T / 0.154) / std::log(10);
    double y = 1.28034 + 0.0709706 * x - 0.245846 * std::pow(x, 2) + 0.0151415 * std::pow(x, 3);
    double epsilon = std::pow(10, y);
    return epsilon;
}

double pQCD::speed2(double T) const {
    double x = std::log(T / 0.154) / std::log(10);
    double y = 0.28923 - 0.120985 * x + 0.0111729 * std::pow(x, 2) - 0.000362774 * std::pow(x, 3);
    double cs2 = std::pow(10, y);
    return cs2;
}

double pQCD::pressure(double T) const {
    double x = std::log(T / 0.154) / std::log(10);
    double y = 1.39089 - 0.162945 * x + 0.00777701 * std::pow(x, 2) - 0.00027842 * std::pow(x, 3);
    double p = std::pow(10, y);
    return p;
}

double pQCD::d2as_dmu2(double mu) const {
    double numerator1 = 22.0644 + 2.79253 * std::pow(std::log(0.777632 * std::pow(mu, 2) * std::pow(X, 2)), 2) - 26.477;
    return numerator1;
}
