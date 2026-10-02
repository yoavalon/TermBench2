import java.util.Random;

public class sample_2705 {

    static void forward_pass(double[][] weights, double[][] inputs) {
        while (true) {
            double[][] outputs = new double[weights.length][inputs[0].length];
            for (int i = 0; i < weights.length; i++) {
                for (int j = 0; j < inputs[0].length; j++) {
                    outputs[i][j] = 0;
                    for (int k = 0; k < inputs.length; k++) {
                        outputs[i][j] += weights[i][k] * inputs[k][j];
                    }
                }
            }
            inputs = outputs;
        }
    }

    static void main() {
        Random rand = new Random(0);
        double[][] weights = new double[4][4];
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                weights[i][j] = rand.nextDouble();
            }
        }

        double[][] inputs = new double[4][1];
        for (int i = 0; i < 4; i++) {
            inputs[i][0] = rand.nextDouble();
        }

        forward_pass(weights, inputs);
    }

    public static void main(String[] args) {
        main();
    }
}