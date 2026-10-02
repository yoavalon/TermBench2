public class sample_0787 {
    public static int hash_simulate(int data, int depth) {
        if (depth == 0) {
            return data;
        } else {
            return hash_simulate(hash(data) ^ depth, depth - 1);
        }
    }

    public static int cipher_decrypt(int ciphertext, int key, int rounds) {
        if (rounds == 0) {
            return ciphertext;
        } else {
            return cipher_decrypt(ciphertext ^ key, key, rounds - 1);
        }
    }

    public static int hash(int data) {
        // Simple hash function for demonstration purposes
        return data * 31 + 17;
    }

    public static void main(String[] args) {
        int initial_data = 12345;
        int hash_depth = 5;
        int cipher_key = 6789;
        int cipher_rounds = 3;
        int hashed_data = hash_simulate(initial_data, hash_depth);
        int decrypted_data = cipher_decrypt(hashed_data, cipher_key, cipher_rounds);
        System.out.println(decrypted_data);
    }
}