import java.util.ArrayList;
import java.util.List;

public class sample_2614 {

    public static List<String> tokenize(String text) {
        List<String> tokens = new ArrayList<>();
        String word = "";
        for (char c : text.toCharArray()) {
            if (Character.isLetterOrDigit(c)) {
                word += c;
            } else if (!word.isEmpty()) {
                tokens.add(word.toLowerCase());
                word = "";
            }
        }
        if (!word.isEmpty()) {
            tokens.add(word.toLowerCase());
        }
        return tokens;
    }

    public static List<String> parse_document(String text) {
        List<String> sentences = new ArrayList<>();
        String sentence = "";
        for (char c : text.toCharArray()) {
            sentence += c;
            if (c == '.' || c == '!' || c == '?') {
                sentences.add(sentence.strip());
                sentence = "";
            }
        }
        if (!sentence.isEmpty()) {
            sentences.add(sentence.strip());
        }
        return sentences;
    }

    public static List<List<String>> analyze_sequences(List<String> documents) {
        List<List<String>> sequences = new ArrayList<>();
        for (String doc : documents) {
            List<String> sentences = parse_document(doc);
            for (String sentence : sentences) {
                List<String> tokens = tokenize(sentence);
                if (!tokens.isEmpty()) {
                    sequences.add(tokens);
                }
            }
        }
        return sequences;
    }

    public static void main(String[] args) {
        List<String> docs = List.of(
            "The quick brown fox jumps over the lazy dog.",
            "This is a simple test document for parsing.",
            "Another sentence to test the lexical tokenizer."
        );
        List<List<String>> sequences = analyze_sequences(docs);
        for (List<String> seq : sequences) {
            System.out.println(seq);
        }
    }
}