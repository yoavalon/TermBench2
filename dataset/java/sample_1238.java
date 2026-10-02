import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_1238 {
    public static byte[] process_data(byte[] data) throws NoSuchAlgorithmException {
        MessageDigest hash_function = MessageDigest.getInstance("SHA-256");
        hash_function.update(data);
        byte[] hashed_data = hash_function.digest();
        byte[] cipher = new byte[data.length];
        for (int i = 0; i < data.length; i++) {
            cipher[i] = (byte) (data[i] ^ hashed_data[i]);
        }
        return cipher;
    }

    public static void main(String[] args) {
        try {
            byte[] data = "Example Data".getBytes();
            byte[] processed = process_data(data);
            System.out.println(new String(processed));
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        }
    }
}