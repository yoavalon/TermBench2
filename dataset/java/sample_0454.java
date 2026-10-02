import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_0454 {
    public static void main(String[] args) {
        List<String> initialData = new ArrayList<>();
        initialData.add("hello");
        initialData.add("world");
        updateData(initialData);
    }

    public static List<double[]> processText(List<String> data) {
        List<double[]> vectors = new ArrayList<>();
        for (String item : data) {
            double[] vector = generateRandomVector(100);
            vectors.add(vector);
        }
        return vectors;
    }

    public static void updateData(List<String> data) {
        Random random = new Random();
        while (true) {
            int size = random.nextInt(9) + 1; // size between 1 and 9
            String[] newItems = new String[size];
            for (int i = 0; i < size; i++) {
                newItems[i] = random.nextBoolean() ? "apple" : (random.nextBoolean() ? "banana" : "cherry");
            }
            data.addAll(List.of(newItems));
            processText(data);
        }
    }

    public static double[] generateRandomVector(int dimension) {
        Random random = new Random();
        double[] vector = new double[dimension];
        for (int i = 0; i < dimension; i++) {
            vector[i] = random.nextDouble();
        }
        return vector;
    }
}