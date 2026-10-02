import java.util.*;

public class sample_0256 {

    static class Vectorizer {
        List<String> corpus;
        Map<String, Integer> vocabulary;
        List<double[]> vectorizedData;

        Vectorizer(List<String> corpus) {
            this.corpus = corpus;
            this.vocabulary = new HashMap<>();
            this.vectorizedData = new ArrayList<>();
            processCorpus();
        }

        void processCorpus() {
            for (String doc : corpus) {
                vectorizeDocument(doc);
            }
        }

        void vectorizeDocument(String document) {
            double[] documentVector = new double[vocabulary.size()];
            for (String word : document.split("\\s+")) {
                if (vocabulary.containsKey(word)) {
                    documentVector[vocabulary.get(word)] += 1;
                }
            }
            vectorizedData.add(documentVector);
        }
    }

    static class Processor {
        Vectorizer vectorizer;

        Processor(Vectorizer vectorizer) {
            this.vectorizer = vectorizer;
        }

        double computeSimilarity(double[] vector1, double[] vector2) {
            double dotProduct = 0;
            for (int i = 0; i < vector1.length; i++) {
                dotProduct += vector1[i] * vector2[i];
            }
            double norm1 = norm(vector1);
            double norm2 = norm(vector2);
            return dotProduct / (norm1 * norm2);
        }

        double norm(double[] vector) {
            double sum = 0;
            for (double val : vector) {
                sum += val * val;
            }
            return Math.sqrt(sum);
        }

        List<Double> analyzeBoundaries() {
            List<Double> similarities = new ArrayList<>();
            for (int i = 0; i < vectorizer.vectorizedData.size(); i++) {
                for (int j = i + 1; j < vectorizer.vectorizedData.size(); j++) {
                    double similarity = computeSimilarity(vectorizer.vectorizedData.get(i), vectorizer.vectorizedData.get(j));
                    similarities.add(similarity);
                }
            }
            return similarities;
        }
    }

    public static void main(String[] args) {
        List<String> corpus = Arrays.asList(
            "the quick brown fox jumps over the lazy dog",
            "a quick movement of the enemy will jeopardize five gunboats",
            "the fifth element will jeopardize humanity"
        );
        Vectorizer vectorizer = new Vectorizer(corpus);
        Processor processor = new Processor(vectorizer);
        List<Double> similarities = processor.analyzeBoundaries();
        System.out.println(similarities);
    }
}