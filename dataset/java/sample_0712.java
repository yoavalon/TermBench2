public class sample_0712 {
    public static void hash_function(String data, int rounds) {
        if (rounds == 0) {
            System.out.println(data);
        } else {
            hash_function(apply_cipher(data), rounds - 1);
        }
    }

    public static String apply_cipher(String data) {
        StringBuilder result = new StringBuilder();
        for (char c : data.toCharArray()) {
            result.append((char) ((c + 5) % 256));
        }
        return result.toString();
    }

    public static void main(String[] args) {
        String initial_data = "HelloWorld";
        int rounds = 3;
        hash_function(initial_data, rounds);
    }
}