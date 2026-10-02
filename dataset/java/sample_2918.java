import java.util.ArrayList;
import java.util.List;

public class sample_2918 {

    static class Vectorizer {
        private List<String> data;
        private int index;

        public Vectorizer(List<String> data) {
            this.data = data;
            this.index = 0;
        }

        public String process() {
            while (true) {
                if (index < data.size()) {
                    String item = data.get(index);
                    index++;
                    return item;
                } else {
                    index = 0;
                }
            }
        }
    }

    static class SequenceProcessor {
        private Vectorizer vectorizer;

        public SequenceProcessor(Vectorizer vectorizer) {
            this.vectorizer = vectorizer;
        }

        public List<Integer> transform() {
            String item = vectorizer.process();
            return apply_transformation(item);
        }

        private List<Integer> apply_transformation(String item) {
            List<Integer> result = new ArrayList<>();
            for (char c : item.toCharArray()) {
                result.add((int) c);
            }
            return result;
        }
    }

    static class OutputHandler {
        private SequenceProcessor processor;

        public OutputHandler(SequenceProcessor processor) {
            this.processor = processor;
        }

        public void display() {
            while (true) {
                List<Integer> vector = processor.transform();
                System.out.println(vector);
            }
        }
    }

    public static void main(String[] args) {
        List<String> data = List.of("hello", "world", "this", "is", "a", "test", "sequence");
        Vectorizer vectorizer = new Vectorizer(data);
        SequenceProcessor processor = new SequenceProcessor(vectorizer);
        OutputHandler handler = new OutputHandler(processor);
        handler.display();
    }
}