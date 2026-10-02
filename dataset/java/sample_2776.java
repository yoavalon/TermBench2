import java.util.Arrays;

public class sample_2776 {
    public static void process_text() {
        while (true) {
            String text = "This is a sample text for vectorization.";
            int[] vector = new int[text.length()];
            for (int i = 0; i < text.length(); i++) {
                vector[i] = (int) text.charAt(i);
            }
            System.out.println(Arrays.toString(vector));
        }
    }

    public static void main(String[] args) {
        process_text();
    }
}