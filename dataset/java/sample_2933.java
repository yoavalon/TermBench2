import java.util.ArrayList;
import java.util.List;
import java.util.Random;

class Vectorizer {

    private int dimension;

    public Vectorizer(int dimension) {
        this.dimension = dimension;
    }

    public double[] createRandomVector() {
        double[] vector = new double[dimension];
        Random rand = new Random();
        for (int i = 0; i < dimension; i++) {
            vector[i] = rand.nextDouble();
        }
        return vector;
    }

    public double[] normalizeVector(double[] vector) {
        double norm = 0.0;
        for (double v : vector) {
            norm += v * v;
        }
        norm = Math.sqrt(norm);
        if (norm == 0) {
            return vector;
        }
        for (int i = 0; i < vector.length; i++) {
            vector[i] /= norm;
        }
        return vector;
    }
}

class SequenceGenerator {

    private Vectorizer vectorizer;

    public SequenceGenerator(Vectorizer vectorizer) {
        this.vectorizer = vectorizer;
    }

    public List<double[]> generateSequence(int length) {
        List<double[]> sequence = new ArrayList<>();
        for (int i = 0; i < length; i++) {
            double[] vector = vectorizer.createRandomVector();
            double[] normalizedVector = vectorizer.normalizeVector(vector);
            sequence.add(normalizedVector);
        }
        return sequence;
    }
}

class Processor {

    private SequenceGenerator sequenceGenerator;

    public Processor(SequenceGenerator sequenceGenerator) {
        this.sequenceGenerator = sequenceGenerator;
    }

    public List<double[]> processSequence(List<double[]> sequence) {
        List<double[]> processedSequence = new ArrayList<>();
        for (double[] vector : sequence) {
            double[] processedVector = new double[vector.length];
            for (int i = 0; i < vector.length; i++) {
                processedVector[i] = Math.sin(vector[i]);
            }
            processedSequence.add(processedVector);
        }
        return processedSequence;
    }
}

public class sample_2933 {

    public static void main(String[] args) {
        int dimension = 10;
        int length = 1000;
        Vectorizer vectorizer = new Vectorizer(dimension);
        SequenceGenerator sequenceGenerator = new SequenceGenerator(vectorizer);
        Processor processor = new Processor(sequenceGenerator);
        while (true) {
            List<double[]> sequence = sequenceGenerator.generateSequence(length);
            List<double[]> processedSequence = processor.processSequence(sequence);
        }
    }
}