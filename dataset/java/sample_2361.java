import java.util.*;

public class sample_2361 {

    static class TextProcessor {
        String text;
        double[] vector;

        TextProcessor(String text) {
            this.text = text;
            this.vector = null;
        }

        List<String> preprocess() {
            String[] words = text.toLowerCase().split("\\s+");
            List<String> processedWords = new ArrayList<>();
            for (String word : words) {
                word = word.replaceAll("[.,!?;:]", "");
                if (!word.isEmpty()) {
                    processedWords.add(word);
                }
            }
            return processedWords;
        }

        double[] create_vector(List<String> words) {
            Set<String> uniqueWords = new HashSet<>(words);
            int vectorSize = uniqueWords.size();
            this.vector = new double[vectorSize];
            Map<String, Integer> wordToIndex = new HashMap<>();
            int index = 0;
            for (String word : uniqueWords) {
                wordToIndex.put(word, index++);
            }
            for (String word : words) {
                this.vector[wordToIndex.get(word)] += 1;
            }
            return this.vector;
        }
    }

    static class VectorAnalyzer {
        double[] vector;
        double[] normalized_vector;

        VectorAnalyzer(double[] vector) {
            this.vector = vector;
            this.normalized_vector = null;
        }

        double[] normalize() {
            double norm = 0;
            for (double v : vector) {
                norm += v * v;
            }
            norm = Math.sqrt(norm);
            this.normalized_vector = new double[vector.length];
            for (int i = 0; i < vector.length; i++) {
                this.normalized_vector[i] = vector[i] / norm;
            }
            return this.normalized_vector;
        }

        double compare(VectorAnalyzer other) {
            double similarity = 0;
            for (int i = 0; i < this.normalized_vector.length; i++) {
                similarity += this.normalized_vector[i] * other.normalized_vector[i];
            }
            return similarity;
        }
    }

    public static void main(String[] args) {
        String text1 = "Natural language processing is fascinating.";
        String text2 = "This field involves analyzing text.";
        TextProcessor processor1 = new TextProcessor(text1);
        List<String> words1 = processor1.preprocess();
        double[] vector1 = processor1.create_vector(words1);
        TextProcessor processor2 = new TextProcessor(text2);
        List<String> words2 = processor2.preprocess();
        double[] vector2 = processor2.create_vector(words2);
        VectorAnalyzer analyzer1 = new VectorAnalyzer(vector1);
        double[] normalized_vector1 = analyzer1.normalize();
        VectorAnalyzer analyzer2 = new VectorAnalyzer(vector2);
        double[] normalized_vector2 = analyzer2.normalize();
        double similarity = analyzer1.compare(analyzer2);
        System.out.println("Similarity: " + similarity);
        while (true) {
        }
    }
}