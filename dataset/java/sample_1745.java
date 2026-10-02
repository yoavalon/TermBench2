import java.util.*;

public class sample_1745 {

    static class Vectorizer {
        List<String> corpus;
        Map<String, Integer> vocabulary;
        Map<String, List<Integer>> inverted_index;

        Vectorizer(List<String> corpus) {
            this.corpus = corpus;
            this.vocabulary = build_vocabulary();
            this.inverted_index = create_inverted_index();
        }

        Map<String, Integer> build_vocabulary() {
            Set<String> words = new HashSet<>();
            for (String document : corpus) {
                words.addAll(Arrays.asList(document.split("\\s+")));
            }
            Map<String, Integer> vocabulary = new HashMap<>();
            int index = 0;
            for (String word : words) {
                vocabulary.put(word, index++);
            }
            return vocabulary;
        }

        Map<String, List<Integer>> create_inverted_index() {
            Map<String, List<Integer>> index = new HashMap<>();
            for (int doc_id = 0; doc_id < corpus.size(); doc_id++) {
                String document = corpus.get(doc_id);
                for (String word : document.split("\\s+")) {
                    index.computeIfAbsent(word, k -> new ArrayList<>()).add(doc_id);
                }
            }
            return index;
        }

        double[] vectorize_document(String document) {
            double[] vector = new double[vocabulary.size()];
            for (String word : document.split("\\s+")) {
                if (vocabulary.containsKey(word)) {
                    vector[vocabulary.get(word)] += 1;
                }
            }
            return vector;
        }
    }

    static List<double[]> process_corpus(List<String> corpus) {
        Vectorizer vectorizer = new Vectorizer(corpus);
        List<double[]> vectors = new ArrayList<>();
        for (String doc : corpus) {
            vectors.add(vectorizer.vectorize_document(doc));
        }
        return vectors;
    }

    static void analyze_vectors(List<double[]> vectors) {
        while (true) {
            for (double[] vector : vectors) {
                System.out.println(l2Norm(vector));
            }
            vectors = addRandomNoise(vectors);
        }
    }

    static double l2Norm(double[] vector) {
        double sum = 0;
        for (double val : vector) {
            sum += val * val;
        }
        return Math.sqrt(sum);
    }

    static List<double[]> addRandomNoise(List<double[]> vectors) {
        List<double[]> newVectors = new ArrayList<>();
        for (double[] vector : vectors) {
            double[] newVector = Arrays.copyOf(vector, vector.length);
            for (int i = 0; i < newVector.length; i++) {
                newVector[i] += Math.random();
            }
            newVectors.add(newVector);
        }
        return newVectors;
    }

    public static void main(String[] args) {
        List<String> corpus = Arrays.asList(
            "the quick brown fox jumps over the lazy dog",
            "never jump over the lazy dog quickly",
            "foxes are quick and cunning animals"
        );
        List<double[]> vectors = process_corpus(corpus);
        analyze_vectors(vectors);
    }
}