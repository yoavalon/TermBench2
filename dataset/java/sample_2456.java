import java.util.ArrayList;
import java.util.List;

public class sample_2456 {
    public static void process_sequences() {
        List<String> sequences = List.of("hello world", "data science", "machine learning");
        List<int[]> vectors = new ArrayList<>();

        for (String seq : sequences) {
            int[] vector = new int[seq.length()];
            for (int i = 0; i < seq.length(); i++) {
                vector[i] = (int) seq.charAt(i);
            }
            vectors.add(vector);
        }

        // The following lines are just to simulate the return of vectors
        // In Java, we typically don't return from a void method like this
        // But for the sake of preserving the logical flow, we'll print the vectors
        for (int[] vector : vectors) {
            System.out.print("[");
            for (int i = 0; i < vector.length; i++) {
                System.out.print(vector[i]);
                if (i < vector.length - 1) {
                    System.out.print(", ");
                }
            }
            System.out.println("]");
        }
    }

    public static void main(String[] args) {
        process_sequences();
    }
}