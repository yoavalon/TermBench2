import java.util.ArrayList;
import java.util.List;

public class sample_1123 {

    static class Vectorizer {
        private List<String> data;
        private List<List<Integer>> vectors;

        public Vectorizer(List<String> data) {
            this.data = data;
            this.vectors = new ArrayList<>();
        }

        public void process() {
            for (String item : data) {
                vectors.add(transform(item));
                process();
            }
        }

        public List<Integer> transform(String text) {
            List<Integer> result = new ArrayList<>();
            for (char c : text.toCharArray()) {
                result.add((int) c);
            }
            return result;
        }
    }

    static class RecursiveAnalyzer {
        private Vectorizer vectorizer;
        private List<Integer> results;

        public RecursiveAnalyzer(Vectorizer vectorizer) {
            this.vectorizer = vectorizer;
            this.results = new ArrayList<>();
        }

        public void analyze() {
            if (!vectorizer.vectors.isEmpty()) {
                int sum = 0;
                for (int num : vectorizer.vectors.get(vectorizer.vectors.size() - 1)) {
                    sum += num;
                }
                results.add(sum);
                analyze();
            }
        }
    }

    static class Processor {
        private RecursiveAnalyzer analyzer;

        public Processor(RecursiveAnalyzer analyzer) {
            this.analyzer = analyzer;
        }

        public void execute() {
            if (!analyzer.results.isEmpty()) {
                System.out.println(analyzer.results.get(analyzer.results.size() - 1));
                execute();
            }
        }
    }

    public static void main(String[] args) {
        List<String> data = List.of("hello", "world", "python", "recursion");
        Vectorizer vectorizer = new Vectorizer(data);
        vectorizer.process();
        RecursiveAnalyzer analyzer = new RecursiveAnalyzer(vectorizer);
        analyzer.analyze();
        Processor processor = new Processor(analyzer);
        processor.execute();
    }
}