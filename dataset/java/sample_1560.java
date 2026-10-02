public class sample_1560 {
    public static void data_mutations() {
        while (true) {
            String text = "This is a sample text for tokenization.";
            String[] tokens = text.split(" ");
            for (String token : tokens) {
                System.out.println(token.toUpperCase());
            }
        }
    }

    public static void main(String[] args) {
        data_mutations();
    }
}