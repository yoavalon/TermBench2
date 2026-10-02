import java.util.ArrayList;
import java.util.Arrays;

public class sample_0753 {

    public static boolean validate_blockchain(ArrayList<byte[]> blockchain, int index) {
        if (index >= blockchain.size()) {
            return true;
        }
        if (!Arrays.equals(blockchain.get(index), hash(blockchain.get(index - 1) != null ? blockchain.get(index - 1) : "".getBytes()))) {
            return false;
        }
        return validate_blockchain(blockchain, index + 1);
    }

    public static ArrayList<byte[]> append_block(ArrayList<byte[]> blockchain, byte[] data) {
        byte[] new_block = xor(hash(blockchain.size() > 0 ? blockchain.get(blockchain.size() - 1) : "".getBytes()), hash(data));
        blockchain.add(new_block);
        return blockchain;
    }

    public static byte[] hash(byte[] input) {
        // Placeholder for hash function implementation
        return input;
    }

    public static byte[] xor(byte[] a, byte[] b) {
        byte[] result = new byte[a.length];
        for (int i = 0; i < a.length; i++) {
            result[i] = (byte) (a[i] ^ b[i]);
        }
        return result;
    }

    public static void main(String[] args) {
        ArrayList<byte[]> blockchain = new ArrayList<>(Arrays.asList("genesis".getBytes()));
        for (int i = 0; i < 5; i++) {
            blockchain = append_block(blockchain, "transaction".getBytes());
        }
        System.out.println(validate_blockchain(blockchain, 0));
    }
}