#ifndef PQCD_HPP
#define PQCD_HPP

class pQCD {
public:
    explicit pQCD(double X);
    double constraints(double a, double b, double c, double d, double e) const;
    double number_density(double T) const;
    double edens(double T) const;
    double speed2(double T) const;
    double pressure(double T) const;

private:
    double X;
    double d2as_dmu2(double mu) const;
};

#endif // PQCD_HPP
