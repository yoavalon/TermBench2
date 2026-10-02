import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class sample_0744 {
    public static List<String> tokenize(String text) {
        if (text.isEmpty()) {
            return new ArrayList<>();
        }
        String[] parts = text.split(" ", 2);
        String first = parts[0];
        String rest = parts.length > 1 ? parts[1] : "";
        List<String> result = new ArrayList<>();
        result.add(first);
        result.addAll(tokenize(rest));
        return result;
    }

    public static List<List<String>> parse_document(String document) {
        if (document.isEmpty()) {
            return new ArrayList<>();
        }
        String[] parts = document.split("\n", 2);
        String firstLine = parts[0];
        String restLines = parts.length > 1 ? parts[1] : "";
        List<List<String>> result = new ArrayList<>();
        result.add(tokenize(firstLine));
        result.addAll(parse_document(restLines));
        return result;
    }

    public static void main(String[] args) {
        String document = "Hello world\nThis is a test\\Of recursive tokenization";
        List<List<String>> result = parse_document(document);
        System.out.println(result);
    }
}