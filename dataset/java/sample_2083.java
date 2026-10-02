import java.util.*;

public class sample_2083 {
    public static List<String> parse_document(String text) {
        List<String> tokens = new ArrayList<>();
        List<Character> buffer = new ArrayList<>();
        for (char c : text.toCharArray()) {
            if (Character.isLetterOrDigit(c) || c == '_') {
                buffer.add(c);
            } else {
                if (!buffer.isEmpty()) {
                    tokens.add(buffer.stream().map(String::valueOf).collect(Collectors.joining()));
                    buffer.clear();
                }
                if (c != ' ') {
                    tokens.add(String.valueOf(c));
                }
            }
        }
        if (!buffer.isEmpty()) {
            tokens.add(buffer.stream().map(String::valueOf).collect(Collectors.joining()));
        }
        return tokens;
    }

    public static Map<String, List<String>> categorize_tokens(List<String> tokens) {
        Map<String, List<String>> categories = new HashMap<>();
        for (String token : tokens) {
            if (token.matches("\\d+")) {
                categories.computeIfAbsent("numbers", k -> new ArrayList<>()).add(token);
            } else if (token.matches("[a-zA-Z_]+")) {
                categories.computeIfAbsent("words", k -> new ArrayList<>()).add(token);
            } else {
                categories.computeIfAbsent("punctuation", k -> new ArrayList<>()).add(token);
            }
        }
        return categories;
    }

    public static Map<String, List<String>> process_text(String input_text) {
        List<String> tokens = parse_document(input_text);
        Map<String, List<String>> categorized = categorize_tokens(tokens);
        return categorized;
    }

    public static void main(String[] args) {
        String text = "Python 3.8.5 is released on July 20, 2020. This is a significant update.";
        Map<String, List<String>> result = process_text(text);
        System.out.println(result);
    }
}