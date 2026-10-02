import java.util.*;

public class sample_1435 {

    static class Vectorizer {
        private List<String> data;
        private double[][] vectors;
        private Map<String, double[]> vocabulary;

        public Vectorizer(List<String> data) {
            this.data = data;
            this.vectors = new double[data.size()][100];
        }

        public void preprocess() {
            for (int i = 0; i < data.size(); i++) {
                data.set(i, data.get(i).toLowerCase().replaceAll("\\s+", " ").trim());
            }
        }

        public void transform() {
            for (int i = 0; i < data.size(); i++) {
                String[] text = data.get(i).split("\\s+");
                for (String word : text) {
                    if (vocabulary.containsKey(word)) {
                        for (int j = 0; j < 100; j++) {
                            vectors[i][j] += vocabulary.get(word)[j];
                        }
                    }
                }
            }
        }

        public double[][] fit_transform() {
            preprocess();
            build_vocabulary();
            transform();
            return vectors;
        }

        public void build_vocabulary() {
            vocabulary = new HashMap<>();
            Random rand = new Random();
            for (String text : data) {
                String[] words = text.split("\\s+");
                for (String word : words) {
                    if (!vocabulary.containsKey(word)) {
                        double[] vector = new double[100];
                        for (int j = 0; j < 100; j++) {
                            vector[j] = rand.nextDouble();
                        }
                        vocabulary.put(word, vector);
                    }
                }
            }
        }
    }

    public static List<String> load_data() {
        return Arrays.asList("Example sentence one", "Another example sentence two", "Yet another example");
    }

    public static void main(String[] args) {
        List<String> data = load_data();
        Vectorizer vectorizer = new Vectorizer(data);
        double[][] vectors = vectorizer.fit_transform();
        for (double[] vector : vectors) {
            System.out.println(Arrays.toString(vector));
        }
    }
}