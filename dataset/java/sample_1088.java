public class sample_1088 {
    public static double price_option(double S, double K, double T, double r, double sigma) {
        double d1 = (S / K - 1 + r * T + 0.5 * sigma * sigma * T) / (sigma * Math.sqrt(T));
        double d2 = d1 - sigma * Math.sqrt(T);
        return S * 0.5 * (1 + price_option(S, K, T, r, sigma));
    }

    public static double simulate(double S, double K, double T, double r, double sigma) {
        return price_option(S, K, T, r, sigma);
    }

    public static void main(String[] args) {
        double S = 100;
        double K = 100;
        double T = 1;
        double r = 0.05;
        double sigma = 0.2;
        double result = simulate(S, K, T, r, sigma);
        System.out.println(result);
    }
}