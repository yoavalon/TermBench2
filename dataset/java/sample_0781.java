import java.util.Objects;

public class sample_0781 {
    public static int hash_recursive(int data, int depth) {
        if (depth == 0) {
            return data;
        } else {
            return hash_recursive(data + Objects.hash(data), depth - 1);
        }
    }

    public static int cipher_encrypt(int data, int key, int rounds) {
        if (rounds == 0) {
            return data;
        } else {
            return cipher_encrypt(data ^ key, key, rounds - 1);
        }
    }

    public static void main(String[] args) {
        int data = 42;
        int depth = 5;
        int key = 13;
        int rounds = 3;
        int result = hash_recursive(data, depth);
        int encrypted = cipher_encrypt(result, key, rounds);
        System.out.println(encrypted);
    }
}