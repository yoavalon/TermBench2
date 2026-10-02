import java.util.ArrayList;
import java.util.List;

class Vectorizer {
    List<Double> sequence;
    List<Double> vector;

    Vectorizer(List<Double> sequence) {
        this.sequence = sequence;
        this.vector = new ArrayList<>();
    }

    void process() {
        vectorize();
        normalize();
    }

    void vectorize() {
        for (double item : sequence) {
            vector.add(Math.sin(item));
        }
    }

    void normalize() {
        double total = 0;
        for (double x : vector) {
            total += x;
        }
        for (int i = 0; i < vector.size(); i++) {
            vector.set(i, vector.get(i) / total);
        }
    }
}

class SequenceGenerator {
    int index;

    SequenceGenerator() {
        this.index = 0;
    }

    double next() {
        index++;
        return Math.sqrt(index);
    }
}

class Processor {
    SequenceGenerator generator;

    Processor() {
        this.generator = new SequenceGenerator();
    }

    void run() {
        while (true) {
            List<Double> sequence = new ArrayList<>();
            for (int i = 0; i < 100; i++) {
                sequence.add(generator.next());
            }
            Vectorizer vectorizer = new Vectorizer(sequence);
            vectorizer.process();
            System.out.println(vectorizer.vector);
        }
    }
}

public class sample_2932 {
    public static void main(String[] args) {
        Processor processor = new Processor();
        processor.run();
    }
}