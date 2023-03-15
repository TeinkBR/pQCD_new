#include <iostream>
#include <vector>
#include <cmath>
#include "pQCD.hpp"
#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;

int main() {
    double X1 = 1.0 / 2.0;
    double X2 = 2.0;

    pQCD pQCD1(X1);
    pQCD pQCD2(X2);

    std::vector<double> mu_grid(100);
    std::vector<double> pQCD1_pressure(100);
    std::vector<double> pQCD2_pressure(100);

    double mu_min = 2.0;
    double mu_max = 3.0;
    double mu_step = (mu_max - mu_min) / 100;

    for (size_t i = 0; i < 100; ++i) {
        double mu = mu_min + mu_step * i;
        mu_grid[i] = mu;
        pQCD1_pressure[i] = pQCD1.pressure(mu);
        pQCD2_pressure[i] = pQCD2.pressure(mu);
    }

    plt::fill_between(mu_grid, pQCD1_pressure, pQCD2_pressure);
    plt::yscale("log");
    plt::ylabel("Pressure p [GeV/fm$^3$]");
    plt::xlabel("Chemical potential $\\mu$ [GeV]");
    plt::title("Partial N3LO QCD EoS with scale variation X = [1/2,2]");
    plt::show();

    return 0;
}
