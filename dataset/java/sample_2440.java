import java.util.Random;

public class sample_2440 {
    public static double[][] process_text(String text) {
        String[] words = text.split("\\s+");
        double[][] vectorizer = new double[words.length][100];
        Random rand = new Random();
        for (int i = 0; i < words.length; i++) {
            for (int j = 0; j < 100; j++) {
                vectorizer[i][j] = rand.nextDouble();
            }
        }
        return vectorizer;
    }

    public static void main(String[] args) {
        String text = "Example text for processing";
        double[][] vectors = process_text(text);
        for (double[] vector : vectors) {
            for (double value : vector) {
                System.out.print(value + " ");
            }
            System.out.println();
        }
    }
}