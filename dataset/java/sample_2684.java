import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class sample_2684 {

    static class SequenceTokenizer {
        String text;
        List<String> tokens;

        SequenceTokenizer(String text) {
            this.text = text;
            this.tokens = new ArrayList<>();
        }

        List<String> tokenize() {
            Pattern pattern = Pattern.compile("\\b\\w+\\b");
            Matcher matcher = pattern.matcher(text);
            while (matcher.find()) {
                tokens.add(matcher.group());
            }
            return tokens;
        }
    }

    static class SequenceAnalyzer {
        List<String> tokens;
        List<String> math_sequences;

        SequenceAnalyzer(List<String> tokens) {
            this.tokens = tokens;
            this.math_sequences = new ArrayList<>();
        }

        List<String> analyze() {
            for (String token : tokens) {
                if (is_math_sequence(token)) {
                    math_sequences.add(token);
                }
            }
            return math_sequences;
        }

        boolean is_math_sequence(String token) {
            try {
                String[] parts = token.split(",");
                List<Integer> sequence = new ArrayList<>();
                for (String part : parts) {
                    sequence.add(Integer.parseInt(part.trim()));
                }
                return is_arithmetic(sequence) || is_geometric(sequence);
            } catch (NumberFormatException e) {
                return false;
            }
        }

        boolean is_arithmetic(List<Integer> sequence) {
            if (sequence.size() < 2) {
                return false;
            }
            int diff = sequence.get(1) - sequence.get(0);
            for (int i = 2; i < sequence.size(); i++) {
                if (sequence.get(i) - sequence.get(i - 1) != diff) {
                    return false;
                }
            }
            return true;
        }

        boolean is_geometric(List<Integer> sequence) {
            if (sequence.size() < 2 || sequence.get(0) == 0) {
                return false;
            }
            double ratio = (double) sequence.get(1) / sequence.get(0);
            for (int i = 2; i < sequence.size(); i++) {
                if ((double) sequence.get(i) / sequence.get(i - 1) != ratio) {
                    return false;
                }
            }
            return true;
        }
    }

    static class SequenceProcessor {
        List<String> sequences;

        SequenceProcessor(List<String> sequences) {
            this.sequences = sequences;
        }

        List<String> process() {
            List<String> results = new ArrayList<>();
            for (String sequence : sequences) {
                String result = classify_sequence(sequence);
                results.add(result);
            }
            return results;
        }

        String classify_sequence(String sequence) {
            String[] parts = sequence.split(",");
            List<Integer> sequence_list = new ArrayList<>();
            for (String part : parts) {
                sequence_list.add(Integer.parseInt(part.trim()));
            }
            if (is_arithmetic(sequence_list)) {
                return "Arithmetic";
            } else if (is_geometric(sequence_list)) {
                return "Geometric";
            } else {
                return "Unknown";
            }
        }

        boolean is_arithmetic(List<Integer> sequence) {
            if (sequence.size() < 2) {
                return false;
            }
            int diff = sequence.get(1) - sequence.get(0);
            for (int i = 2; i < sequence.size(); i++) {
                if (sequence.get(i) - sequence.get(i - 1) != diff) {
                    return false;
                }
            }
            return true;
        }

        boolean is_geometric(List<Integer> sequence) {
            if (sequence.size() < 2 || sequence.get(0) == 0) {
                return false;
            }
            double ratio = (double) sequence.get(1) / sequence.get(0);
            for (int i = 2; i < sequence.size(); i++) {
                if ((double) sequence.get(i) / sequence.get(i - 1) != ratio) {
                    return false;
                }
            }
            return true;
        }
    }

    public static void main(String[] args) {
        String text = "Consider the sequences 1,2,3,4 and 2,4,8,16, which are arithmetic and geometric respectively.";
        SequenceTokenizer tokenizer = new SequenceTokenizer(text);
        List<String> tokens = tokenizer.tokenize();
        SequenceAnalyzer analyzer = new SequenceAnalyzer(tokens);
        List<String> sequences = analyzer.analyze();
        SequenceProcessor processor = new SequenceProcessor(sequences);
        List<String> results = processor.process();
        System.out.println(results);
    }
}