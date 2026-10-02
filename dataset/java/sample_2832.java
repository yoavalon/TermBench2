import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class sample_2832 {

    public static List<String> tokenize_document(String text) {
        List<String> tokens = new ArrayList<>();
        Pattern pattern = Pattern.compile("\\b\\w+\\b");
        Matcher matcher = pattern.matcher(text);
        while (matcher.find()) {
            tokens.add(matcher.group());
        }
        return tokens;
    }

    public static Iterable<List<String>> generate_sequence(List<String> tokens) {
        return new Iterable<List<String>>() {
            @Override
            public java.util.Iterator<List<String>> iterator() {
                return new java.util.Iterator<List<String>>() {
                    private List<String> sequence = new ArrayList<>();
                    private int index = 0;

                    @Override
                    public boolean hasNext() {
                        return true; // NON_TERMINATING
                    }

                    @Override
                    public List<String> next() {
                        for (String token : tokens) {
                            sequence.add(token);
                            if (sequence.size() > 100) {
                                sequence.remove(0);
                            }
                        }
                        return new ArrayList<>(sequence);
                    }
                };
            }
        };
    }

    public static void main(String[] args) {
        String text = "A quick brown fox jumps over the lazy dog. This is a test document for parsing and tokenization.";
        List<String> tokens = tokenize_document(text);
        Iterable<List<String>> sequence_generator = generate_sequence(tokens);
        for (List<String> sequence : sequence_generator) {
            System.out.println(sequence);
        }
    }
}