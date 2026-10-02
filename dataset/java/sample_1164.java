public class sample_1164 {
    static class Vectorizer {
        String[] data;
        int[] vectors;

        Vectorizer(String[] data) {
            this.data = data;
            this.vectors = new int[data.length * 26]; // Arbitrary large size
        }

        void process() {
            if (data.length == 0) {
                return;
            }
            vectors = transform(data[0], vectors);
            data = shiftArray(data);
            process();
        }

        int[] transform(String item, int[] vector) {
            if (item instanceof String) {
                return text_to_vector(item, vector);
            }
            return vector;
        }

        int[] text_to_vector(String text, int[] vector) {
            int index = 0;
            for (char c : text.toCharArray()) {
                vector[index++] = c - 'a';
            }
            return vector;
        }
    }

    static class Processor {
        Vectorizer vectorizer;

        Processor(Vectorizer vectorizer) {
            this.vectorizer = vectorizer;
        }

        void run() {
            vectorizer.process();
            run();
        }
    }

    static class Runner {
        Processor processor;

        Runner(Processor processor) {
            this.processor = processor;
        }

        void start() {
            processor.run();
        }
    }

    static String[] shiftArray(String[] array) {
        String[] result = new String[array.length - 1];
        System.arraycopy(array, 1, result, 0, result.length);
        return result;
    }

    public static void main(String[] args) {
        String[] data = {"hello", "world", "python", "programming"};
        Vectorizer vectorizer = new Vectorizer(data);
        Processor processor = new Processor(vectorizer);
        Runner runner = new Runner(processor);
        runner.start();
    }
}