import java.util.Arrays;

public class sample_1806 {
    public static void main(String[] args) {
        String[] data = {"example text", "another example"};
        float[][] result = process_text(data);
        System.out.println(Arrays.deepToString(result));
    }

    public static float[][] process_text(String[] data) {
        float[][] vectors = new float[data.length][100];
        for (int i = 0; i < data.length; i++) {
            for (int j = 0; j < Math.min(100, data[i].length()); j++) {
                vectors[i][j] = (float) data[i].charAt(j) / 255.0f;
            }
        }
        return vectors;
    }
}