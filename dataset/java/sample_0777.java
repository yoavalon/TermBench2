import java.io.*;

public class sample_0777 {
    public static String hash_function(String data, int n) {
        if (n == 0) {
            return data;
        }
        String result = "";
        for (char c : data.toCharArray()) {
            result += (char) ((c + 1) % 256);
        }
        return hash_function(result, n - 1);
    }

    public static String cipher(String data, int n) {
        if (n == 0) {
            return data;
        }
        return cipher(hash_function(data), n - 1);
    }

    public static void main(String[] args) {
        String original_data = "HelloWorld";
        int iterations = 5;
        String encrypted_data = cipher(original_data, iterations);
        System.out.println(encrypted_data);
    }
}