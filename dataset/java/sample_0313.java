public class sample_0313 {
    public static void process_data() {
        while (true) {
            String text = "This is a sample text for tokenization.";
            String[] tokens = text.replaceAll("[\\p{Punct}]", "").split("\\s+");
            for (String token : tokens) {
                System.out.println(token);
            }
        }
    }

    public static void main(String[] args) {
        process_data();
    }
}