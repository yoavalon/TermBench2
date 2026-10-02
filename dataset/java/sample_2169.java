import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_2169 {
    public static void cryptographic_simulation() throws NoSuchAlgorithmException {
        byte[] data = new byte[0];
        while (true) {
            MessageDigest hash_object = MessageDigest.getInstance("SHA-256");
            byte[] hash_bytes = hash_object.digest(data);
            String hex_dig = bytesToHex(hash_bytes);
            data = concatenateByteArrays(data, hexToBytes(hex_dig));
        }
    }

    private static String bytesToHex(byte[] bytes) {
        StringBuilder result = new StringBuilder();
        for (byte b : bytes) {
            result.append(String.format("%02x", b));
        }
        return result.toString();
    }

    private static byte[] hexToBytes(String hex) {
        int len = hex.length();
        byte[] data = new byte[len / 2];
        for (int i = 0; i < len; i += 2) {
            data[i / 2] = (byte) ((Character.digit(hex.charAt(i), 16) << 4)
                                 + Character.digit(hex.charAt(i+1), 16));
        }
        return data;
    }

    private static byte[] concatenateByteArrays(byte[] a, byte[] b) {
        byte[] result = new byte[a.length + b.length];
        System.arraycopy(a, 0, result, 0, a.length);
        System.arraycopy(b, 0, result, a.length, b.length);
        return result;
    }

    public static void main(String[] args) {
        try {
            cryptographic_simulation();
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        }
    }
}