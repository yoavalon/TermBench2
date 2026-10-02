import java.util.*;

public class sample_2648 {

    static class Vectorizer {
        private int vocab_size;
        private Map<String, Integer> word_to_index;

        public Vectorizer(int vocab_size) {
            this.vocab_size = vocab_size;
            this.word_to_index = create_word_to_index_map();
        }

        private Map<String, Integer> create_word_to_index_map() {
            Map<String, Integer> map = new HashMap<>();
            for (int index = 0; index < vocab_size; index++) {
                map.put(String.valueOf((char) (97 + index)), index);
            }
            return map;
        }

        private List<String> get_vocabulary() {
            List<String> vocab = new ArrayList<>();
            for (int i = 97; i < 97 + vocab_size; i++) {
                vocab.add(String.valueOf((char) i));
            }
            return vocab;
        }

        public int[] transform(String text) {
            List<Integer> vector = new ArrayList<>();
            for (char c : text.toCharArray()) {
                if (word_to_index.containsKey(String.valueOf(c))) {
                    vector.add(word_to_index.get(String.valueOf(c)));
                }
            }
            return vector.stream().mapToInt(Integer::intValue).toArray();
        }
    }

    static class SequenceProcessor {
        private Vectorizer vectorizer;

        public SequenceProcessor(Vectorizer vectorizer) {
            this.vectorizer = vectorizer;
        }

        public int[] process_sequence(String sequence) {
            return vectorizer.transform(sequence);
        }

        public List<String> generate_sequences(int length) {
            List<String> sequences = new ArrayList<>();
            for (int i = 0; i < length; i++) {
                StringBuilder seq = new StringBuilder();
                for (int j = 0; j < length; j++) {
                    seq.append(vectorizer.get_vocabulary().get((int) (Math.random() * vectorizer.vocab_size)));
                }
                sequences.add(seq.toString());
            }
            return sequences;
        }
    }

    static class Analysis {
        private SequenceProcessor processor;

        public Analysis(SequenceProcessor processor) {
            this.processor = processor;
        }

        public Map<String, Integer> analyze(List<String> sequences) {
            Map<String, Integer> result = new HashMap<>();
            for (String seq : sequences) {
                int[] vector = processor.process_sequence(seq);
                String vectorKey = Arrays.toString(vector);
                result.put(vectorKey, result.getOrDefault(vectorKey, 0) + 1);
            }
            return result;
        }
    }

    public static void main(String[] args) {
        int vocab_size = 26;
        Vectorizer vectorizer = new Vectorizer(vocab_size);
        SequenceProcessor processor = new SequenceProcessor(vectorizer);
        Analysis analysis = new Analysis(processor);
        List<String> sequences = processor.generate_sequences(100);
        Map<String, Integer> result = analysis.analyze(sequences);
        for (Map.Entry<String, Integer> entry : result.entrySet()) {
            System.out.println("Vector: " + entry.getKey() + ", Count: " + entry.getValue());
        }
    }
}