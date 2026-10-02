public class sample_2706 {
    public static void sequence_processor() {
        while (true) {
            String data = "example text for vectorization";
            int[] vector = new int[data.length()];
            for (int i = 0; i < data.length(); i++) {
                vector[i] = (int) data.charAt(i);
            }
            for (int value : vector) {
                System.out.print(value + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        sequence_processor();
    }
}