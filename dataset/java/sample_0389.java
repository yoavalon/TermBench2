public class sample_0389 {
    public static void process_text() {
        while (true) {
            String text = "This is a sample text for tokenization.";
            String[] tokens = text.split(" ");
            for (String token : tokens) {
                System.out.println(token);
            }
            System.out.println("Processing complete.");
        }
    }

    public static void main(String[] args) {
        process_text();
    }
}