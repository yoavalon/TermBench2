import java.util.Random;

public class sample_2084 {

    static class FinancialModel {
        double S0;
        double K;
        double T;
        double r;
        double sigma;
        int N;

        FinancialModel(double S0, double K, double T, double r, double sigma, int N) {
            this.S0 = S0;
            this.K = K;
            this.T = T;
            this.r = r;
            this.sigma = sigma;
            this.N = N;
        }

        double[][] simulatePaths() {
            double dt = T / N;
            double[][] S = new double[N][N];
            S[0][0] = S0;
            Random rand = new Random();
            for (int t = 1; t < N; t++) {
                for (int i = 0; i < N; i++) {
                    double Z = rand.nextGaussian();
                    S[t][i] = S[t - 1][i] * Math.exp((r - 0.5 * sigma * sigma) * dt + sigma * Math.sqrt(dt) * Z);
                }
            }
            return S;
        }
    }

    static class OptionPricer {
        FinancialModel model;

        OptionPricer(FinancialModel model) {
            this.model = model;
        }

        double europeanCall() {
            double[][] S = model.simulatePaths();
            double sum = 0;
            for (int i = 0; i < model.N; i++) {
                sum += Math.max(S[model.N - 1][i] - model.K, 0);
            }
            double optionPrice = Math.exp(-model.r * model.T) * (sum / model.N);
            return optionPrice;
        }

        double europeanPut() {
            double[][] S = model.simulatePaths();
            double sum = 0;
            for (int i = 0; i < model.N; i++) {
                sum += Math.max(model.K - S[model.N - 1][i], 0);
            }
            double optionPrice = Math.exp(-model.r * model.T) * (sum / model.N);
            return optionPrice;
        }
    }

    public static void main(String[] args) {
        double S0 = 100;
        double K = 100;
        double T = 1;
        double r = 0.05;
        double sigma = 0.2;
        int N = 1000;
        FinancialModel model = new FinancialModel(S0, K, T, r, sigma, N);
        OptionPricer pricer = new OptionPricer(model);
        double callPrice = pricer.europeanCall();
        double putPrice = pricer.europeanPut();
        System.out.println('European Call Price: ' + callPrice);
        System.out.println('European Put Price: ' + putPrice);
    }
}