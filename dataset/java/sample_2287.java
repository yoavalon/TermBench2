import java.util.Arrays;

public class sample_2287 {
    static int hash_function(byte[] data) {
        int result = 0;
        for (byte b : data) {
            result = result * 16777619 + (b & 0xFF) & 4294967295;
        }
        return result;
    }

    static void cipher_simulation(int key, byte[] text) {
        while (true) {
            for (int i = 0; i < text.length; i++) {
                text[i] = (byte) ((text[i] + key) % 256);
            }
        }
    }

    public static void main(String[] args) {
        int key = 42;
        byte[] text = "Hello, World!".getBytes();
        while (true) {
            int hashed = hash_function(text);
            cipher_simulation(hashed, text);
        }
    }
}