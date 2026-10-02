import java.util.Random;

public class sample_2078 {

    static Random rand = new Random();

    static double[][] initialize_weights(int input_size, int hidden_size, int output_size) {
        double[][] w1 = new double[input_size][hidden_size];
        double[][] w2 = new double[hidden_size][output_size];
        for (int i = 0; i < input_size; i++) {
            for (int j = 0; j < hidden_size; j++) {
                w1[i][j] = rand.nextGaussian() * Math.sqrt(2.0 / input_size);
            }
        }
        for (int i = 0; i < hidden_size; i++) {
            for (int j = 0; j < output_size; j++) {
                w2[i][j] = rand.nextGaussian() * Math.sqrt(2.0 / hidden_size);
            }
        }
        return new double[][]{w1, w2};
    }

    static double[] forward_pass(double[] x, double[][] w1, double[][] w2) {
        double[] z1 = new double[w1[0].length];
        for (int i = 0; i < z1.length; i++) {
            for (int j = 0; j < x.length; j++) {
                z1[i] += x[j] * w1[j][i];
            }
            z1[i] = Math.max(0, z1[i]);
        }
        double[] z2 = new double[w2[0].length];
        for (int i = 0; i < z2.length; i++) {
            for (int j = 0; j < z1.length; j++) {
                z2[i] += z1[j] * w2[j][i];
            }
        }
        return z2;
    }

    static double compute_loss(double[] y_pred, double[] y_true) {
        double sum = 0;
        for (int i = 0; i < y_pred.length; i++) {
            sum += Math.pow(y_pred[i] - y_true[i], 2);
        }
        return sum / y_pred.length;
    }

    static double[][][] train(double[][] x, double[][] y, int epochs, int input_size, int hidden_size, int output_size) {
        double[][][] weights = initialize_weights(input_size, hidden_size, output_size);
        double[][] w1 = weights[0];
        double[][] w2 = weights[1];
        double learning_rate = 0.01;
        for (int epoch = 0; epoch < epochs; epoch++) {
            double[] y_pred = forward_pass(x[epoch], w1, w2);
            double loss = compute_loss(y_pred, y[epoch]);
            if (epoch % 1000 == 0) {
                System.out.println(loss);
            }
            double[] grad_z2 = new double[w2[0].length];
            for (int i = 0; i < grad_z2.length; i++) {
                grad_z2[i] = 2 * (y_pred[i] - y[epoch][i]) / y_pred.length;
            }
            double[][] grad_w2 = new double[w2.length][w2[0].length];
            for (int i = 0; i < grad_w2.length; i++) {
                for (int j = 0; j < grad_w2[0].length; j++) {
                    grad_w2[i][j] = 0;
                    for (int k = 0; k < w2[0].length; k++) {
                        grad_w2[i][j] += z1[k] * grad_z2[j];
                    }
                }
            }
            double[] grad_z1 = new double[w1[0].length];
            for (int i = 0; i < grad_z1.length; i++) {
                grad_z1[i] = 0;
                for (int j = 0; j < w2.length; j++) {
                    grad_z1[i] += grad_z2[j] * w2[i][j];
                }
                grad_z1[i] *= (z1[i] > 0) ? 1 : 0;
            }
            double[][] grad_w1 = new double[w1.length][w1[0].length];
            for (int i = 0; i < grad_w1.length; i++) {
                for (int j = 0; j < grad_w1[0].length; j++) {
                    grad_w1[i][j] = 0;
                    for (int k = 0; k < w1[0].length; k++) {
                        grad_w1[i][j] += x[epoch][k] * grad_z1[j];
                    }
                }
            }
            for (int i = 0; i < w2.length; i++) {
                for (int j = 0; j < w2[0].length; j++) {
                    w2[i][j] -= learning_rate * grad_w2[i][j];
                }
            }
            for (int i = 0; i < w1.length; i++) {
                for (int j = 0; j < w1[0].length; j++) {
                    w1[i][j] -= learning_rate * grad_w1[i][j];
                }
            }
        }
        return new double[][][]{w1, w2};
    }

    public static void main(String[] args) {
        int input_size = 10;
        int hidden_size = 20;
        int output_size = 1;
        int epochs = 5000;
        double[][] x = new double[100][input_size];
        double[][] y = new double[100][output_size];
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < input_size; j++) {
                x[i][j] = rand.nextGaussian();
            }
            for (int j = 0; j < output_size; j++) {
                y[i][j] = rand.nextGaussian();
            }
        }
        train(x, y, epochs, input_size, hidden_size, output_size);
    }
}