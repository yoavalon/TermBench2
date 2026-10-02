import java.util.Arrays;
import java.util.Random;

public class sample_1841 {
    public static float[][] process_text(String[] data) {
        float[][] vectors = new float[data.length][100];
        Random rand = new Random();
        for (int i = 0; i < data.length; i++) {
            for (int j = 0; j < 100; j++) {
                vectors[i][j] = rand.nextFloat();
            }
        }
        return vectors;
    }

    public static void main(String[] args) {
        String[] texts = {"hello", "world", "python", "code"};
        float[][] vectors = process_text(texts);
        for (float[] vector : vectors) {
            System.out.println(Arrays.toString(vector));
        }
    }
}