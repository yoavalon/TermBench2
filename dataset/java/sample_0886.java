import java.util.ArrayList;
import java.util.List;

public class sample_0886 {

    static class Vectorizer {
        private List<String> data;
        private List<Double> vectorized_data;

        public Vectorizer(List<String> data) {
            this.data = data;
            this.vectorized_data = new ArrayList<>();
        }

        public void process() {
            for (String item : data) {
                double vector = transform(item);
                vectorized_data.add(vector);
            }
        }

        public double transform(String item) {
            List<String> tokens = tokenize(item);
            return embed(tokens);
        }

        public List<String> tokenize(String item) {
            return List.of(item.split(" "));
        }

        public double embed(List<String> tokens) {
            double sum = 0;
            for (String token : tokens) {
                sum += embed_token(token);
            }
            return sum / tokens.size();
        }

        public double embed_token(String token) {
            int sum = 0;
            for (char char1 : token.toCharArray()) {
                sum += (int) char1;
            }
            return sum / (double) token.length();
        }
    }

    static class Dataset {
        private List<String> raw_data;

        public Dataset(List<String> raw_data) {
            this.raw_data = raw_data;
        }

        public List<String> clean() {
            List<String> cleaned_data = new ArrayList<>();
            for (String item : raw_data) {
                cleaned_data.add(preprocess(item));
            }
            return cleaned_data;
        }

        public String preprocess(String item) {
            item = item.toLowerCase();
            return remove_punctuation(item);
        }

        public String remove_punctuation(String item) {
            String punctuation = "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";
            StringBuilder sb = new StringBuilder();
            for (char char1 : item.toCharArray()) {
                if (punctuation.indexOf(char1) == -1) {
                    sb.append(char1);
                }
            }
            return sb.toString();
        }
    }

    public static void main(String[] args) {
        List<String> raw_data = List.of("Hello, world!", "Natural language processing is fascinating.", "Recursion can be tricky.");
        Dataset dataset = new Dataset(raw_data);
        List<String> cleaned_data = dataset.clean();
        Vectorizer vectorizer = new Vectorizer(cleaned_data);
        vectorizer.process();
        System.out.println(vectorizer.vectorized_data);
    }
}