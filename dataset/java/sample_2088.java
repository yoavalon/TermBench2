import java.util.ArrayList;
import java.util.List;

public class sample_2088 {

    static class Vector {
        List<Double> elements;

        Vector(List<Double> elements) {
            this.elements = elements;
        }

        double magnitude() {
            double sum = 0;
            for (double x : elements) {
                sum += Math.pow(x, 2);
            }
            return Math.sqrt(sum);
        }

        void normalize() {
            double mag = magnitude();
            for (int i = 0; i < elements.size(); i++) {
                elements.set(i, elements.get(i) / mag);
            }
        }
    }

    static double cosine_similarity(Vector vec1, Vector vec2) {
        if (vec1.elements.size() != vec2.elements.size()) {
            throw new IllegalArgumentException("Vectors must be of the same length");
        }
        double dot_product = 0;
        for (int i = 0; i < vec1.elements.size(); i++) {
            dot_product += vec1.elements.get(i) * vec2.elements.get(i);
        }
        return dot_product / (vec1.magnitude() * vec2.magnitude());
    }

    static List<Tuple<Integer, Integer, Double>> process_vectors(List<List<Double>> data) {
        List<Vector> vectors = new ArrayList<>();
        for (List<Double> vec : data) {
            vectors.add(new Vector(vec));
        }
        List<Tuple<Integer, Integer, Double>> results = new ArrayList<>();
        for (int i = 0; i < vectors.size(); i++) {
            for (int j = i + 1; j < vectors.size(); j++) {
                vectors.get(i).normalize();
                vectors.get(j).normalize();
                double similarity = cosine_similarity(vectors.get(i), vectors.get(j));
                results.add(new Tuple<>(i, j, similarity));
            }
        }
        return results;
    }

    static class Tuple<X, Y, Z> {
        public final X x;
        public final Y y;
        public final Z z;

        public Tuple(X x, Y y, Z z) {
            this.x = x;
            this.y = y;
            this.z = z;
        }
    }

    public static void main(String[] args) {
        List<List<Double>> data = new ArrayList<>();
        data.add(List.of(1.0, 2.0, 3.0));
        data.add(List.of(4.0, 5.0, 6.0));
        data.add(List.of(7.0, 8.0, 9.0));
        List<Tuple<Integer, Integer, Double>> similarities = process_vectors(data);
        for (Tuple<Integer, Integer, Double> sim : similarities) {
            System.out.printf("Similarity between vector %d and %d: %.4f%n", sim.x, sim.y, sim.z);
        }
    }
}