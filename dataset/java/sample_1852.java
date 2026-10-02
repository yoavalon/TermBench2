import java.util.Arrays;

public class sample_1852 {
    public static void main(String[] args) {
        String text = "Hello world";
        double[] result = vectorizeText(text);
        System.out.println(Arrays.toString(result));
    }

    public static double[] vectorizeText(String text) {
        String[] words = text.split(" ");
        double[][] vectors = new double[words.length][];
        for (int i = 0; i < words.length; i++) {
            String word = words[i];
            vectors[i] = new double[word.length()];
            for (int j = 0; j < word.length(); j++) {
                vectors[i][j] = (int) word.charAt(j) * 0.1;
            }
        }
        return Arrays.stream(vectors).mapToDouble(arr -> Arrays.stream(arr).average().orElse(0.0)).toArray();
    }
}