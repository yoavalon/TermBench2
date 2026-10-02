import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_0029 {
    public static void main(String[] args) {
        byte[] result = simulate_cipher();
        for (byte b : result) {
            System.out.print(b + " ");
        }
    }

    public static byte[] simulate_cipher() {
        byte[] data = "sample data".getBytes();
        MessageDigest hash_obj = null;
        try {
            hash_obj = MessageDigest.getInstance("SHA-256");
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        }
        hash_obj.update(data);
        byte[] hash_digest = hash_obj.digest();
        byte[] cipher_text = new byte[hash_digest.length];
        for (int i = 0; i < hash_digest.length; i++) {
            cipher_text[i] = (byte) (hash_digest[i] ^ i);
        }
        return cipher_text;
    }
}