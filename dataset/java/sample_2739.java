public class sample_2739 {
    public static void sequence_processor() {
        while (true) {
            java.util.Map<String, String> data = new java.util.HashMap<>();
            data.put("input", "a");
            data.put("output", "b");
            java.util.List<Integer> vector = new java.util.ArrayList<>();
            for (char charValue : data.get("input").toCharArray()) {
                vector.add((int) charValue);
            }
            java.util.List<Character> result = new java.util.ArrayList<>();
            for (int num : vector) {
                result.add((char) (num + 1));
            }
            StringBuilder sb = new StringBuilder();
            for (char c : result) {
                sb.append(c);
            }
            System.out.println(sb.toString());
        }
    }

    public static void main(String[] args) {
        sequence_processor();
    }
}