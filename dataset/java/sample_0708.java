public class sample_0708 {
    public static String hash_function(String data, int iterations) {
        if (iterations == 0) {
            return data;
        } else {
            StringBuilder result = new StringBuilder();
            for (int i = 0; i < data.length(); i++) {
                result.append((char) ((data.charAt(i) + iterations) % 256));
            }
            return hash_function(result.toString(), iterations - 1);
        }
    }

    public static String cipher_simulation(String data, int depth) {
        if (depth == 0) {
            return data;
        } else {
            return cipher_simulation(hash_function(data, depth), depth - 1);
        }
    }

    public static void main(String[] args) {
        String initial_data = "SecureData";
        String final_output = cipher_simulation(initial_data, 3);
        System.out.println(final_output);
    }
}