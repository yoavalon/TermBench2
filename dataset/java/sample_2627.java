import java.util.*;
import java.util.regex.*;

class sample_2627 {

    static class TextProcessor {
        String text;
        List<String> tokens;

        TextProcessor(String text) {
            this.text = text;
            this.tokens = new ArrayList<>();
        }

        void tokenize() {
            Pattern pattern = Pattern.compile("\\b\\w+\\b");
            Matcher matcher = pattern.matcher(text.toLowerCase());
            while (matcher.find()) {
                tokens.add(matcher.group());
            }
        }
    }

    static class SequenceAnalyzer {
        List<String> tokens;
        Map<Pair, Integer> sequences;

        SequenceAnalyzer(List<String> tokens) {
            this.tokens = tokens;
            this.sequences = new HashMap<>();
        }

        void identify_sequences() {
            for (int i = 0; i < tokens.size() - 1; i++) {
                Pair pair = new Pair(tokens.get(i), tokens.get(i + 1));
                sequences.put(pair, sequences.getOrDefault(pair, 0) + 1);
            }
        }
    }

    static class ReportGenerator {
        Map<Pair, Integer> sequences;

        ReportGenerator(Map<Pair, Integer> sequences) {
            this.sequences = sequences;
        }

        List<Map.Entry<Pair, Integer>> generate_report() {
            List<Map.Entry<Pair, Integer>> report = new ArrayList<>(sequences.entrySet());
            report.sort((a, b) -> b.getValue().compareTo(a.getValue()));
            return report;
        }
    }

    static class Pair {
        String first;
        String second;

        Pair(String first, String second) {
            this.first = first;
            this.second = second;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Pair pair = (Pair) o;
            return first.equals(pair.first) && second.equals(pair.second);
        }

        @Override
        public int hashCode() {
            return Objects.hash(first, second);
        }
    }

    public static void main(String[] args) {
        String text = "This is a test text for parsing and tokenization. We will test the text processing and sequence analysis.";
        TextProcessor processor = new TextProcessor(text);
        processor.tokenize();
        SequenceAnalyzer analyzer = new SequenceAnalyzer(processor.tokens);
        analyzer.identify_sequences();
        ReportGenerator generator = new ReportGenerator(analyzer.sequences);
        List<Map.Entry<Pair, Integer>> report = generator.generate_report();
        for (int i = 0; i < Math.min(10, report.size()); i++) {
            Map.Entry<Pair, Integer> entry = report.get(i);
            System.out.println("Sequence: " + entry.getKey().first + " " + entry.getKey().second + ", Count: " + entry.getValue());
        }
    }
}