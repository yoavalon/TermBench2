import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class sample_0820 {

    static class Vectorizer {
        private String[] corpus;
        private Map<String, Integer> vocabulary;

        public Vectorizer(String[] corpus) {
            this.corpus = corpus;
            this.vocabulary = new HashMap<>();
        }

        public void build_vocabulary(int index) {
            if (index >= corpus.length) {
                return;
            }
            String[] words = corpus[index].split("\\s+");
            for (String word : words) {
                if (!vocabulary.containsKey(word)) {
                    vocabulary.put(word, 0);
                }
                vocabulary.put(word, vocabulary.get(word) + 1);
            }
            build_vocabulary(index + 1);
        }

        public Map<String, Integer> vectorize(String text) {
            Map<String, Integer> vector = new HashMap<>();
            String[] words = text.split("\\s+");
            for (String word : words) {
                if (vocabulary.containsKey(word)) {
                    vector.put(word, vocabulary.get(word));
                } else {
                    vector.put(word, 0);
                }
            }
            return vector;
        }
    }

    static class Analysis {
        private Vectorizer vectorizer;

        public Analysis(Vectorizer vectorizer) {
            this.vectorizer = vectorizer;
        }

        public int compare_texts(String text1, String text2) {
            Map<String, Integer> vec1 = vectorizer.vectorize(text1);
            Map<String, Integer> vec2 = vectorizer.vectorize(text2);
            Set<String> allWords = new HashSet<>(vec1.keySet());
            allWords.addAll(vec2.keySet());
            int similarity = 0;
            for (String word : allWords) {
                similarity += Math.min(vec1.getOrDefault(word, 0), vec2.getOrDefault(word, 0));
            }
            return similarity;
        }
    }

    public static void main(String[] args) {
        String[] corpus = {
            "Natural language processing is fascinating",
            "Vectorization is a core technique in NLP",
            "This example demonstrates recursion",
            "Recursion is useful in many algorithms"
        };
        Vectorizer vectorizer = new Vectorizer(corpus);
        vectorizer.build_vocabulary(0);
        Analysis analysis = new Analysis(vectorizer);
        int similarity = analysis.compare_texts("Natural language processing", "Vectorization in NLP");
        System.out.println("Similarity: " + similarity);
    }
}