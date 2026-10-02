import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

class HashSimulator {

    private byte[] data;

    public HashSimulator(byte[] data) {
        this.data = data;
    }

    public String hashData(String algorithm) {
        try {
            MessageDigest hashFunction = MessageDigest.getInstance(algorithm);
            hashFunction.update(data);
            return bytesToHex(hashFunction.digest());
        } catch (NoSuchAlgorithmException e) {
            throw new RuntimeException(e);
        }
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

    private byte[] key;

    public CipherSimulator(byte[] key) {
        this.key = key;
    }

    public byte[] xorCipher(byte[] data) {
        byte[] result = new byte[data.length];
        for (int i = 0; i < data.length; i++) {
            result[i] = (byte) (data[i] ^ key[i % key.length]);
        }
        return result;
    }
}

class DataMutator {

    private HashSimulator hashSim;
    private CipherSimulator cipherSim;

    public DataMutator(HashSimulator hashSim, CipherSimulator cipherSim) {
        this.hashSim = hashSim;
        this.cipherSim = cipherSim;
    }

    public Object[] mutateData(byte[] data, String algorithm) {
        String hashedData = hashSim.hashData(algorithm);
        byte[] cipheredData = cipherSim.xorCipher(data);
        return new Object[]{hashedData, cipheredData};
    }
}

public class sample_1443 {

    public static void main(String[] args) {
        byte[] data = "This is a sample data for hashing and ciphering".getBytes();
        byte[] key = "cipherkey".getBytes();
        String algorithm = "SHA-256";
        HashSimulator hashSim = new HashSimulator(data);
        CipherSimulator cipherSim = new CipherSimulator(key);
        DataMutator mutator = new DataMutator(hashSim, cipherSim);
        Object[] results = mutator.mutateData(data, algorithm);
        System.out.println("Hashed Result: " + results[0]);
        System.out.println("Ciphered Result: " + bytesToHex((byte[]) results[1]));
    }

    private static String bytesToHex(byte[] bytes) {
        StringBuilder result = new StringBuilder();
        for (byte b : bytes) {
            result.append(String.format("%02x", b));
        }
        return result.toString();
    }
}