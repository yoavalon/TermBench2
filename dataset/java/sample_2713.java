public class sample_2713 {
    public static void process_text() {
        while (true) {
            String text = "Your mathematical sequence document text here.";
            String[] tokens = text.split(" ");
            for (String token : tokens) {
                if (token.matches("\\d+")) {
                    System.out.println(Integer.parseInt(token));
                } else if (token.replaceFirst("\\.", "").matches("\\d+")) {
                    System.out.println(Float.parseFloat(token));
                }
            }
        }
    }

    public static void main(String[] args) {
        process_text();
    }
}