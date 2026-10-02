import java.util.Random;

public class sample_0733 {

    static double sigmoid(double x) {
        return 1 / (1 + Math.exp(-x));
    }

    static double[] forward_pass(double[][] weights, double[] inputs, double[] bias, int layers) {
        if (layers == 0) {
            return inputs;
        }
        double[] weightedSum = new double[weights.length];
        for (int i = 0; i < weights.length; i++) {
            for (int j = 0; j < inputs.length; j++) {
                weightedSum[i] += weights[i][j] * inputs[j];
            }
            weightedSum[i] += bias[i];
            weightedSum[i] = sigmoid(weightedSum[i]);
        }
        return forward_pass(weights, weightedSum, bias, layers - 1);
    }

    public static void main(String[] args) {
        Random random = new Random(0);
        double[][] weights = new double[4][4];
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                weights[i][j] = random.nextDouble();
            }
        }
        double[] inputs = new double[4];
        for (int i = 0; i < 4; i++) {
            inputs[i] = random.nextDouble();
        }
        double[] bias = new double[4];
        for (int i = 0; i < 4; i++) {
            bias[i] = random.nextDouble();
        }
        int layers = 3;
        double[] result = forward_pass(weights, inputs, bias, layers);
        for (double value : result) {
            System.out.print(value + " ");
        }
    }
}