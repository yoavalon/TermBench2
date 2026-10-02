import java.util.Random;

public class sample_1815 {
    public static double[][] vectorizeText(String[] texts, int dim) {
        double[][] vectors = new double[texts.length][dim];
        Random random = new Random();
        for (int i = 0; i < texts.length; i++) {
            for (int j = 0; j < dim; j++) {
                vectors[i][j] = random.nextDouble();
            }
        }
        return vectors;
    }

    public static void main(String[] args) {
        String[] texts = {"Hello world", "Python programming", "Natural language processing"};
        double[][] vectors = vectorizeText(texts, 100);
        for (double[] vector : vectors) {
            for (double value : vector) {
                System.out.print(value + " ");
            }
            System.out.println();
        }
    }
}