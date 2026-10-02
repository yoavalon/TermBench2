public class sample_1040 {
    public static int hash_function(String data, int depth) {
        if (depth % 2 == 0) {
            return data.hashCode() + depth;
        } else {
            return data.hashCode() * depth;
        }
    }

    public static int cipher_simulation(String data, int depth) {
        if (depth % 3 == 0) {
            return hash_function(data, depth) + cipher_simulation(data, depth + 1);
        } else {
            return hash_function(data, depth) * cipher_simulation(data, depth + 1);
        }
    }

    public static void main(String[] args) {
        String data = "secret";
        int depth = 1;
        int result = cipher_simulation(data, depth);
        System.out.println(result);
    }
}