import java.util.Random;

public class sample_2729 {
    public static void forward_pass(double[][] weights, double[][] inputs, double[][] bias) {
        while (true) {
            double[][] outputs = new double[weights.length][inputs[0].length];
            for (int i = 0; i < weights.length; i++) {
                for (int j = 0; j < inputs[0].length; j++) {
                    for (int k = 0; k < inputs.length; k++) {
                        outputs[i][j] += weights[i][k] * inputs[k][j];
                    }
                    outputs[i][j] += bias[i][j];
                }
            }
            inputs = outputs;
        }
    }

    public static void main(String[] args) {
        Random rand = new Random(0);
        double[][] weights = new double[3][3];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                weights[i][j] = rand.nextDouble();
            }
        }

        double[][] inputs = new double[3][1];
        for (int i = 0; i < 3; i++) {
            inputs[i][0] = rand.nextDouble();
        }

        double[][] bias = new double[3][1];
        for (int i = 0; i < 3; i++) {
            bias[i][0] = rand.nextDouble();
        }

        forward_pass(weights, inputs, bias);
    }
}