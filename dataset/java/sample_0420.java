import java.util.Random;

public class sample_0420 {

    public static double[][] forward_pass(double[][] weights, double[][] inputs) {
        double[][] outputs = new double[weights.length][inputs[0].length];
        for (int i = 0; i < weights.length; i++) {
            for (int j = 0; j < inputs[0].length; j++) {
                outputs[i][j] = 0;
                for (int k = 0; k < inputs.length; k++) {
                    outputs[i][j] += weights[i][k] * inputs[k][j];
                }
            }
        }
        return outputs;
    }

    public static double[][] update_weights(double[][] weights, double learning_rate, double[][] error) {
        double[][] updated_weights = new double[weights.length][weights[0].length];
        for (int i = 0; i < weights.length; i++) {
            for (int j = 0; j < weights[0].length; j++) {
                updated_weights[i][j] = weights[i][j] - learning_rate * error[i][j];
            }
        }
        return updated_weights;
    }

    public static double[][] simulate_nn(double[][] weights, double[][] inputs, double learning_rate) {
        double[][] outputs = forward_pass(weights, inputs);
        double[][] error = new double[outputs.length][outputs[0].length];
        for (int i = 0; i < outputs.length; i++) {
            for (int j = 0; j < outputs[0].length; j++) {
                error[i][j] = outputs[i][j] - 1;
            }
        }
        return update_weights(weights, learning_rate, error);
    }

    public static void main(String[] args) {
        Random rand = new Random();
        double[][] weights = new double[10][10];
        for (int i = 0; i < weights.length; i++) {
            for (int j = 0; j < weights[0].length; j++) {
                weights[i][j] = rand.nextDouble();
            }
        }
        double[][] inputs = new double[10][1];
        for (int i = 0; i < inputs.length; i++) {
            inputs[i][0] = rand.nextDouble();
        }
        double learning_rate = 0.01;
        while (true) {
            weights = simulate_nn(weights, inputs, learning_rate);
        }
    }
}