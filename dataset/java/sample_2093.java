import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import javax.crypto.Mac;
import javax.crypto.spec.SecretKeySpec;
import java.util.Arrays;

class HashSimulator {

    private String key;
    private String message;

    public HashSimulator(String key, String message) {
        this.key = key;
        this.message = message;
    }

    public String hash_message() {
        try {
            MessageDigest md = MessageDigest.getInstance("SHA-256");
            md.update(message.getBytes());
            byte[] digest = md.digest();
            return String.format("%064x", new java.math.BigInteger(1, digest));
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
            return "";
        }
    }

    public String hmac_message() {
        try {
            Mac mac = Mac.getInstance("HmacSHA256");
            SecretKeySpec secretKeySpec = new SecretKeySpec(key.getBytes(), "HmacSHA256");
            mac.init(secretKeySpec);
            byte[] hmacBytes = mac.doFinal(message.getBytes());
            return String.format("%064x", new java.math.BigInteger(1, hmacBytes));
        } catch (Exception e) {
            e.printStackTrace();
            return "";
        }
    }
}

class CipherSimulator {

    private String data;

    public CipherSimulator(String data) {
        this.data = data;
    }

    public String xor_cipher(String key) {
        StringBuilder xorResult = new StringBuilder();
        for (int i = 0; i < data.length(); i++) {
            xorResult.append((char) (data.charAt(i) ^ key.charAt(i % key.length())));
        }
        return xorResult.toString();
    }

    public String shift_cipher(int shift) {
        StringBuilder shiftResult = new StringBuilder();
        for (char c : data.toCharArray()) {
            shiftResult.append((char) ((c + shift) % 256));
        }
        return shiftResult.toString();
    }
}

class DataProcessor {

    private HashSimulator hash_simulator;
    private CipherSimulator cipher_simulator;

    public DataProcessor(HashSimulator hash_simulator, CipherSimulator cipher_simulator) {
        this.hash_simulator = hash_simulator;
        this.cipher_simulator = cipher_simulator;
    }

    public String[] process_data() {
        String hash_result = hash_simulator.hash_message();
        String hmac_result = hash_simulator.hmac_message();
        String xor_result = cipher_simulator.xor_cipher(hash_result.substring(0, 16));
        String shift_result = cipher_simulator.shift_cipher(5);
        return new String[]{hmac_result, xor_result, shift_result};
    }
}

public class sample_2093 {

    public static void main(String[] args) {
        String key = bytesToHex(randomBytes(16));
        String message = "SecureMessage";
        HashSimulator hash_sim = new HashSimulator(key, message);
        CipherSimulator cipher_sim = new CipherSimulator(message);
        DataProcessor data_processor = new DataProcessor(hash_sim, cipher_sim);
        String[] result = data_processor.process_data();
        System.out.println(Arrays.toString(result));
    }

    private static byte[] randomBytes(int length) {
        byte[] bytes = new byte[length];
        new java.security.SecureRandom().nextBytes(bytes);
        return bytes;
    }

    private static String bytesToHex(byte[] bytes) {
        StringBuilder result = new StringBuilder();
        for (byte b : bytes) {
            result.append(String.format("%02x", b));
        }
        return result.toString();
    }
}