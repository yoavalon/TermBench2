import java.util.ArrayList;
import java.util.List;

public class sample_0216 {

    public static void main(String[] args) {
        String document = "Hello world! This is a test document.";
        List<String> result = processDocument(document);
        System.out.println(result);
    }

    static List<String> processDocument(String document) {
        DocumentTokenizer tokenizer = new DocumentTokenizer(document);
        return tokenizer.tokenize();
    }

    static class DocumentTokenizer {
        String text;
        int index;
        List<String> tokens;

        DocumentTokenizer(String text) {
            this.text = text;
            this.index = 0;
            this.tokens = new ArrayList<>();
        }

        List<String> tokenize() {
            while (index < text.length()) {
                char charAt = text.charAt(index);
                if (Character.isLetter(charAt)) {
                    index = parseWord();
                } else if (Character.isWhitespace(charAt)) {
                    index += 1;
                } else {
                    tokens.add(String.valueOf(charAt));
                    index += 1;
                }
            }
            return tokens;
        }

        int parseWord() {
            int start = index;
            while (index < text.length() && Character.isLetter(text.charAt(index))) {
                index += 1;
            }
            String word = text.substring(start, index);
            tokens.add(word);
            return index;
        }
    }
}