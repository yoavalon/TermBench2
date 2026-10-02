import java.util.*;
import java.util.regex.*;

public class sample_1036 {
    public static List<String> tokenizeText(String text) {
        Pattern pattern = Pattern.compile("\\b\\w+\\b");
        Matcher matcher = pattern.matcher(text.toLowerCase());
        List<String> words = new ArrayList<>();
        while (matcher.find()) {
            words.add(matcher.group());
        }
        return words;
    }

    public static double[] vectorize(List<String> wordList) {
        Map<String, Integer> wordCounts = new HashMap<>();
        for (String word : wordList) {
            wordCounts.put(word, wordCounts.getOrDefault(word, 0) + 1);
        }
        List<String> vocabulary = new ArrayList<>(wordCounts.keySet());
        Collections.sort(vocabulary);
        double[] vector = new double[vocabulary.size()];
        for (String word : wordList) {
            if (vocabulary.contains(word)) {
                vector[vocabulary.indexOf(word)] += 1;
            }
        }
        return vector;
    }

    public static void recursiveVectorize(String text) {
        double[] vector = vectorize(tokenizeText(text));
        recursiveVectorize(text);
    }

    public static void main(String[] args) {
        String sampleText = "Recursion is a method where the solution to a problem depends on solutions to smaller instances of the same problem.";
        recursiveVectorize(sampleText);
    }
}