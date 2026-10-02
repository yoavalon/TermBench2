import java.util.Arrays;

public class sample_1829 {

    public static float[] process_data(String[] texts) {
        float[] vectors = new float[texts.length];
        for (int i = 0; i < texts.length; i++) {
            int sum = 0;
            for (char c : texts[i].toCharArray()) {
                sum += (int) c;
            }
            vectors[i] = (float) sum / texts[i].length();
        }
        return vectors;
    }

    public static void main(String[] args) {
        String[] data = {"hello", "world", "python", "vectorization"};
        float[] result = process_data(data);
        System.out.println(Arrays.toString(result));
    }
}