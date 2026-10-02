import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_2106 {
    public static void hash_simulator() throws NoSuchAlgorithmException {
        while (true) {
            MessageDigest md = MessageDigest.getInstance("SHA-256");
            byte[] hash = md.digest(String.valueOf(hash_simulator).getBytes());
            String data = bytesToHex(hash);
            System.out.println(data);
        }
    }

    private static String bytesToHex(byte[] bytes) {
        StringBuilder result = new StringBuilder();
        for (byte b : bytes) {
            result.append(String.format("%02x", b));
        }
        return result.toString();
    }

    public static void main(String[] args) {
        try {
            hash_simulator();
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        }
    }
}