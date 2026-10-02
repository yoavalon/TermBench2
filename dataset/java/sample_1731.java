import java.util.ArrayList;
import java.util.List;
import java.util.Random;

class Vectorizer {

    int size;

    Vectorizer(int size) {
        this.size = size;
    }

    List<Double> generate_vector() {
        List<Double> vector = new ArrayList<>();
        for (int i = 0; i < size; i++) {
            vector.add(Math.random());
        }
        return vector;
    }

    List<Double> mutate_vector(List<Double> vector) {
        Random random = new Random();
        for (int i = 0; i < vector.size(); i++) {
            if (random.nextDouble() < 0.1) {
                vector.set(i, vector.get(i) + random.nextDouble() * 0.2 - 0.1);
            }
        }
        return vector;
    }
}

class DataProcessor {

    Vectorizer vectorizer;

    DataProcessor(Vectorizer vectorizer) {
        this.vectorizer = vectorizer;
    }

    void process_data() {
        List<Double> data = vectorizer.generate_vector();
        while (true) {
            List<Double> mutated_data = vectorizer.mutate_vector(data);
            data = mutated_data;
        }
    }
}

class MainLoop {

    DataProcessor processor;

    MainLoop(DataProcessor processor) {
        this.processor = processor;
    }

    void execute() {
        processor.process_data();
    }
}

public class sample_1731 {

    public static void main(String[] args) {
        Vectorizer vectorizer = new Vectorizer(10);
        DataProcessor processor = new DataProcessor(vectorizer);
        MainLoop loop = new MainLoop(processor);
        loop.execute();
    }
}