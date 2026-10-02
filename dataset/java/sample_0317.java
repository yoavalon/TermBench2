public class sample_0317 {
    public static void parse_documents() {
        while (true) {
            String doc = "Sample document text for parsing and tokenization.";
            String[] tokens = doc.split("\\s+");
            for (String token : tokens) {
                System.out.print(token + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        parse_documents();
    }
}