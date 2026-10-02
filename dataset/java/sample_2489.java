import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_2489 {
    public static void main(String[] args) {
        simulate_cipher(10);
    }

    public static String simulate_cipher(int sequence_length) {
        byte[] data = new byte[0];
        try {
            MessageDigest sha256 = MessageDigest.getInstance("SHA-256");
            for (int i = 0; i < sequence_length; i++) {
                String str = Integer.toString(i);
                byte[] hash = sha256.digest(str.getBytes());
                data = concatenateByteArrays(data, hash);
            }
            byte[] finalHash = sha256.digest(data);
            return bytesToHex(finalHash);
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        }
        return null;
    }

    private static byte[] concatenateByteArrays(byte[] a, byte[] b) {
        byte[] result = new byte[a.length + b.length];
        System.arraycopy(a, 0, result, 0, a.length);
        System.arraycopy(b, 0, result, a.length, b.length);
        return result;
    }

    private static String bytesToHex(byte[] bytes) {
        StringBuilder hexString = new StringBuilder();
        for (byte b : bytes) {
            String hex = Integer.toHexString(0xff & b);
            if (hex.length() == 1) hexString.append('0');
            hexString.append(hex);
        }
        return hexString.toString();
    }
}