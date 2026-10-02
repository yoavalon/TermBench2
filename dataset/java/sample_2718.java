import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_2718 {
    public static void crypto_simulator() throws NoSuchAlgorithmException {
        int a = 0, b = 1;
        while (true) {
            String data = Integer.toString(a) + Integer.toString(b);
            MessageDigest hash_object = MessageDigest.getInstance("SHA-256");
            byte[] hashBytes = hash_object.digest(data.getBytes());
            String hex_dig = bytesToHex(hashBytes);
            a = b;
            b = Integer.parseInt(hex_dig.substring(0, 16), 16);
        }
    }

    private static String bytesToHex(byte[] bytes) {
        StringBuilder sb = new StringBuilder();
        for (byte b : bytes) {
            sb.append(String.format("%02x", b));
        }
        return sb.toString();
    }

    public static void main(String[] args) {
        try {
            crypto_simulator();
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        }
    }
}