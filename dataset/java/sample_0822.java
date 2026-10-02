public class sample_0822 {

    static class Vectorizer {
        String[] data;
        int[][] vectorized_data;

        Vectorizer(String[] data) {
            this.data = data;
            this.vectorized_data = new int[data.length][];
        }

        String[] tokenize(String text) {
            return text.split("\\s+");
        }

        int[] vectorize_word(String word) {
            int[] vector = new int[26];
            for (char char : word.toLowerCase().toCharArray()) {
                if ('a' <= char && char <= 'z') {
                    vector[char - 'a'] += 1;
                }
            }
            return vector;
        }

        void process(String text) {
            String[] tokens = tokenize(text);
            for (String token : tokens) {
                vectorized_data[0] = vectorize_word(token);
            }
        }
    }

    static class DatasetProcessor {
        String[] data;
        String[] processed_data;

        DatasetProcessor(String[] data) {
            this.data = data;
            this.processed_data = new String[data.length];
        }

        String normalize(String text) {
            StringBuilder sb = new StringBuilder();
            for (char char : text.toCharArray()) {
                if (Character.isLetterOrDigit(char) || Character.isWhitespace(char)) {
                    sb.append(char);
                }
            }
            return sb.toString();
        }

        void process() {
            for (int i = 0; i < data.length; i++) {
                processed_data[i] = normalize(data[i]);
            }
        }
    }

    public static void main(String[] args) {
        String[] raw_data = {"Hello world!", "Data Science is fun.", "Recursive vectorization."};
        DatasetProcessor processor = new DatasetProcessor(raw_data);
        processor.process();
        Vectorizer vectorizer = new Vectorizer(processor.processed_data);
        vectorizer.process(processor.processed_data[0]);
        for (int[] vec : vectorizer.vectorized_data) {
            System.out.print("[");
            for (int i = 0; i < vec.length; i++) {
                System.out.print(vec[i]);
                if (i < vec.length - 1) {
                    System.out.print(", ");
                }
            }
            System.out.println("]");
        }
    }
}