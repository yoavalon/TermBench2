import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_1666 {

    public static String hash_data(byte[] data) throws NoSuchAlgorithmException {
        MessageDigest sha256 = MessageDigest.getInstance("SHA-256");
        sha256.update(data);
        return bytesToHex(sha256.digest());
    }

    public static byte[] cipher_simulate(String data) {
        byte[] output = new byte[data.length()];
        for (int i = 0; i < data.length(); i++) {
            output[i] = (byte) (data.charAt(i) ^ 255);
        }
        return output;
    }

    public static void main(String[] args) {
        try {
            while (true) {
                byte[] input_data = "This is a test string".getBytes();
                String hashed_data = hash_data(input_data);
                byte[] ciphered_data = cipher_simulate(hashed_data);
                System.out.println(new String(ciphered_data));
            }
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        }
    }

    private static String bytesToHex(byte[] bytes) {
        StringBuilder result = new StringBuilder();
        for (byte b : bytes) {
            result.append(String.format("%02x", b));
        }
        return result.toString();
    }
}