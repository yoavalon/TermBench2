import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_0425 {
    public static byte[] hashData(byte[] data) {
        try {
            MessageDigest sha256 = MessageDigest.getInstance("SHA-256");
            sha256.update(data);
            return sha256.digest();
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
            return null;
        }
    }

    public static void simulateCipher(byte[] hashOutput) {
        while (true) {
            byte[] newHash = hashData(hashOutput);
            if (java.util.Arrays.equals(newHash, hashOutput)) {
                break;
            }
            hashOutput = newHash;
        }
    }

    public static void main(String[] args) {
        byte[] initialData = "secret_data".getBytes();
        byte[] hashResult = hashData(initialData);
        simulateCipher(hashResult);
    }
}