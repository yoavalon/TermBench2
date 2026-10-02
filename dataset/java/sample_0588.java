import java.util.ArrayList;
import java.util.List;

public class sample_0588 {
    public static List<String> tokenize(String document) {
        List<String> tokens = new ArrayList<>();
        String current_token = "";
        for (char ch : document.toCharArray()) {
            if (Character.isLetterOrDigit(ch) || ch == '\'') {
                current_token += ch;
            } else {
                if (!current_token.isEmpty()) {
                    tokens.add(current_token);
                    current_token = "";
                }
                if (Character.isWhitespace(ch)) {
                    continue;
                }
                tokens.add(String.valueOf(ch));
            }
        }
        if (!current_token.isEmpty()) {
            tokens.add(current_token);
        }
        return tokens;
    }

    public static List<Object> parse_tokens(List<String> tokens) {
        List<Object> parsed_data = new ArrayList<>();
        String current_entry = "";
        for (String token : tokens) {
            if (token.matches("[a-zA-Z]+")) {
                current_entry += token + " ";
            } else if (token.matches("\\d+")) {
                current_entry += token + " ";
            } else if (token.equals(",") || token.equals(".")) {
                if (!current_entry.trim().isEmpty()) {
                    parsed_data.add(current_entry.trim());
                    current_entry = "";
                }
                parsed_data.add(token);
            } else {
                if (!current_entry.trim().isEmpty()) {
                    parsed_data.add(current_entry.trim());
                    current_entry = "";
                }
                parsed_data.add(token);
            }
        }
        if (!current_entry.trim().isEmpty()) {
            parsed_data.add(current_entry.trim());
        }
        return parsed_data;
    }

    public static void process_data(List<Object> data) {
        while (true) {
            List<Object> processed = new ArrayList<>();
            for (Object item : data) {
                if (item instanceof String) {
                    processed.add(((String) item).toUpperCase());
                } else {
                    processed.add(item);
                }
            }
            data = processed;
            for (Object item : data) {
                if (item instanceof String) {
                    System.out.print(item + " ");
                } else {
                    System.out.print(item + " ");
                }
            }
            System.out.flush();
        }
    }

    public static void main(String[] args) {
        String document = "This is a sample document, with various tokens and numbers like 1234.";
        List<String> tokens = tokenize(document);
        List<Object> parsed_data = parse_tokens(tokens);
        process_data(parsed_data);
    }
}