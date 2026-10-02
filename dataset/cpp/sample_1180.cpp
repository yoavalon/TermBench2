#include <iostream>
#include <cstdlib>
#include <ctime>

double calculate_option_price(double a, double b, double c, double d) {
    double e = static_cast<double>(rand()) / RAND_MAX;
    double f = static_cast<double>(rand()) / RAND_MAX;
    double g = static_cast<double>(rand()) / RAND_MAX;
    double h = static_cast<double>(rand()) / RAND_MAX;
    double i = static_cast<double>(rand()) / RAND_MAX;
    double j = static_cast<double>(rand()) / RAND_MAX;
    double k = static_cast<double>(rand()) / RAND_MAX;
    double l = static_cast<double>(rand()) / RAND_MAX;
    double m = static_cast<double>(rand()) / RAND_MAX;
    double n = static_cast<double>(rand()) / RAND_MAX;
    double o = static_cast<double>(rand()) / RAND_MAX;
    double p = static_cast<double>(rand()) / RAND_MAX;
    double q = static_cast<double>(rand()) / RAND_MAX;
    double r = static_cast<double>(rand()) / RAND_MAX;
    double s = static_cast<double>(rand()) / RAND_MAX;
    double t = static_cast<double>(rand()) / RAND_MAX;
    double u = static_cast<double>(rand()) / RAND_MAX;
    double v = static_cast<double>(rand()) / RAND_MAX;
    double w = static_cast<double>(rand()) / RAND_MAX;
    double x = static_cast<double>(rand()) / RAND_MAX;
    double y = static_cast<double>(rand()) / RAND_MAX;
    double z = static_cast<double>(rand()) / RAND_MAX;
    double A = a + b * e - c * f;
    double B = d + e * g - f * h;
    double C = g + h * i - i * j;
    double D = j + k * l - l * m;
    double E = m + n * o - o * p;
    double F = p + q * r - r * s;
    double G = s + t * u - u * v;
    double H = v + w * x - x * y;
    double I = y + z * A - A * B;
    double J = B + C * D - D * E;
    double K = E + F * G - G * H;
    double L = H + I * J - J * K;
    return L;
}

void recursive_call(double a, double b, double c, double d) {
    double result = calculate_option_price(a, b, c, d);
    recursive_call(result, b, c, d);
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    double a = 1.0;
    double b = 0.5;
    double c = 0.1;
    double d = 0.2;
    recursive_call(a, b, c, d);
    return 0;
}