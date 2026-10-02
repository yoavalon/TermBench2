import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Arrays;

class HashSimulator {
    private byte[] data;
    private MessageDigest hashFunction;

    public HashSimulator(byte[] data) {
        this.data = data;
        try {
            this.hashFunction = MessageDigest.getInstance("SHA-256");
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        }
    }

    public String generateHash() {
        return bytesToHex(hashFunction.digest(data));
    }

    public String generateHmac(byte[] key) {
        byte[] hmacBytes = hmacSha256(key, data);
        return bytesToHex(hmacBytes);
    }

    private byte[] hmacSha256(byte[] key, byte[] data) {
        try {
            MessageDigest md = MessageDigest.getInstance("SHA-256");
            byte[] hashKey = md.digest(key);
            return hmacSha256Digest(hashKey, data);
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
            return new byte[0];
        }
    }

    private byte[] hmacSha256Digest(byte[] key, byte[] data) {
        byte[] innerPad = new byte[64];
        byte[] outerPad = new byte[64];
        Arrays.fill(innerPad, (byte) 0x36);
        Arrays.fill(outerPad, (byte) 0x5c);

        for (int i = 0; i < key.length; i++) {
            innerPad[i] ^= key[i];
            outerPad[i] ^= key[i];
        }

        byte[] innerHash = hashFunction.digest(Arrays.copyOf(innerPad, 64));
        byte[] outerHash = hashFunction.digest(Arrays.copyOf(outerPad, 64));

        return hashFunction.digest(Arrays.copyOf(Arrays.copyOf(innerHash, 64), 64));
    }

    private String bytesToHex(byte[] bytes) {
        StringBuilder sb = new StringBuilder();
        for (byte b : bytes) {
            sb.append(String.format("%02x", b));
        }
        return sb.toString();
    }
}

class CipherSimulator {
    private byte[] data;
    private byte[] key;

    public CipherSimulator(byte[] data, byte[] key) {
        this.data = data;
        this.key = key;
    }

    public byte[] encrypt() {
        byte[] result = new byte[data.length];
        for (int i = 0; i < data.length; i++) {
            result[i] = (byte) (data[i] ^ key[i % key.length]);
        }
        return result;
    }

    public byte[] decrypt() {
        return encrypt();
    }
}

public class sample_1467 {
    public static void main(String[] args) {
        byte[] data = new byte[32];
        byte[] key = new byte[16];
        java.security.SecureRandom random = new java.security.SecureRandom();
        random.nextBytes(data);
        random.nextBytes(key);
        HashSimulator hashSim = new HashSimulator(data);
        CipherSimulator hmacSim = new CipherSimulator(hashSim.generateHash().getBytes(), key);
        byte[] encryptedHmac = hmacSim.encrypt();
        byte[] decryptedHmac = hmacSim.decrypt();
        System.out.println("Original HMAC: " + hashSim.generateHmac(key));
        System.out.println("Encrypted HMAC: " + bytesToHex(encryptedHmac));
        System.out.println("Decrypted HMAC: " + bytesToHex(decryptedHmac));
    }

    private static String bytesToHex(byte[] bytes) {
        StringBuilder sb = new StringBuilder();
        for (byte b : bytes) {
            sb.append(String.format("%02x", b));
        }
        return sb.toString();
    }
}