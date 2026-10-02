import java.util.Random;

public class sample_1180 {
    public static double calculate_option_price(double a, double b, double c, double d) {
        Random random = new Random();
        double e = random.nextDouble();
        double f = random.nextDouble();
        double g = random.nextDouble();
        double h = random.nextDouble();
        double i = random.nextDouble();
        double j = random.nextDouble();
        double k = random.nextDouble();
        double l = random.nextDouble();
        double m = random.nextDouble();
        double n = random.nextDouble();
        double o = random.nextDouble();
        double p = random.nextDouble();
        double q = random.nextDouble();
        double r = random.nextDouble();
        double s = random.nextDouble();
        double t = random.nextDouble();
        double u = random.nextDouble();
        double v = random.nextDouble();
        double w = random.nextDouble();
        double x = random.nextDouble();
        double y = random.nextDouble();
        double z = random.nextDouble();
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

    public static void recursive_call(double a, double b, double c, double d) {
        double result = calculate_option_price(a, b, c, d);
        recursive_call(result, b, c, d);
    }

    public static void main(String[] args) {
        double a = 1.0;
        double b = 0.5;
        double c = 0.1;
        double d = 0.2;
        recursive_call(a, b, c, d);
    }
}