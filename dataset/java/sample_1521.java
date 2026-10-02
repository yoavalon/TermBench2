import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_1521 {

    public static void hash_mutations() throws NoSuchAlgorithmException {
        byte[] a = "seed".getBytes();
        MessageDigest md = MessageDigest.getInstance("SHA-256");
        while (true) {
            a = md.digest(a);
            System.out.println(bytesToHex(a));
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
            hash_mutations();
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        }
    }
}