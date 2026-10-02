import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_2487 {

    public static byte[] simulate_cipher(String input_data, int rounds) {
        byte[] data = input_data.getBytes();
        for (int i = 0; i < rounds; i++) {
            MessageDigest hash_object = null;
            try {
                hash_object = MessageDigest.getInstance("SHA-256");
            } catch (NoSuchAlgorithmException e) {
                e.printStackTrace();
            }
            data = hash_object.digest(data);
        }
        return data;
    }

    public static void main(String[] args) {
        byte[] result = simulate_cipher("Hello, World!", 3);
        StringBuilder hexString = new StringBuilder();
        for (byte b : result) {
            String hex = Integer.toHexString(0xff & b);
            if(hex.length() == 1) hexString.append('0');
            hexString.append(hex);
        }
        System.out.println(hexString.toString());
    }
}