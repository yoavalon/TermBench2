import java.util.Arrays;

public class sample_1858 {

    public static float[] forward_pass(float[][] matrix, float[] vector) {
        float[] result = new float[matrix.length];
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < vector.length; j++) {
                result[i] += matrix[i][j] * vector[j];
            }
        }
        return result;
    }

    public static void main(String[] args) {
        float[][] matrix = {
            {0.1f, 0.2f},
            {0.3f, 0.4f}
        };
        float[] vector = {0.5f, 0.6f};
        float[] output = forward_pass(matrix, vector);
        System.out.println(Arrays.toString(output));
    }
}