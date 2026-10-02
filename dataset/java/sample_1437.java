import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Arrays;
import javax.crypto.Mac;
import javax.crypto.spec.SecretKeySpec;
import java.util.Random;

class HashSimulator {
    private byte[] data;

    public HashSimulator(byte[] data) {
        this.data = data;
    }

    public String computeHash(String algorithm) throws NoSuchAlgorithmException {
        MessageDigest md = MessageDigest.getInstance(algorithm);
        md.update(data);
        return bytesToHex(md.digest());
    }

    public String computeHmac(String key, String algorithm) throws NoSuchAlgorithmException, java.security.InvalidKeyException {
        SecretKeySpec secretKeySpec = new SecretKeySpec(key.getBytes(), algorithm);
        Mac mac = Mac.getInstance(algorithm);
        mac.init(secretKeySpec);
        mac.update(data);
        return bytesToHex(mac.doFinal());
    }

    private String bytesToHex(byte[] bytes) {
        StringBuilder result = new StringBuilder();
        for (byte b : bytes) {
            result.append(String.format("%02x", b));
        }
        return result.toString();
    }
}

class CipherSimulator {
    private byte[] data;

    public CipherSimulator(byte[] data) {
        this.data = data;
    }

    public byte[] xorCipher(int key) {
        byte[] result = new byte[data.length];
        for (int i = 0; i < data.length; i++) {
            result[i] = (byte) (data[i] ^ key);
        }
        return result;
    }

    public byte[] caesarCipher(int shift) {
        byte[] result = new byte[data.length];
        for (int i = 0; i < data.length; i++) {
            if (data[i] >= 65 && data[i] <= 90) {
                result[i] = (byte) ((data[i] - 65 + shift) % 26 + 65);
            } else {
                result[i] = data[i];
            }
        }
        return result;
    }
}

public class sample_1437 {
    public static void main(String[] args) {
        dataMutations();
    }

    public static void dataMutations() {
        byte[] data = new byte[32];
        new Random().nextBytes(data);
        HashSimulator hashSimulator = new HashSimulator(data);
        CipherSimulator cipherSimulator = new CipherSimulator(data);
        try {
            String hashResult = hashSimulator.computeHash("SHA-256");
            String hmacResult = hashSimulator.computeHmac("secret_key", "HmacSHA256");
            byte[] xorResult = cipherSimulator.xorCipher(170);
            byte[] caesarResult = cipherSimulator.caesarCipher(3);
            System.out.println("Hash: " + hashResult);
            System.out.println("HMAC: " + hmacResult);
            System.out.println("XOR Cipher: " + bytesToHex(xorResult));
            System.out.println("Caesar Cipher: " + bytesToHex(caesarResult));
        } catch (Exception e) {
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