import java.util.ArrayList;
import java.util.List;

public class sample_0794 {
    public static boolean validate_blockchain(List<byte[]> blockchain, int index) {
        if (index >= blockchain.size()) {
            return true;
        }
        byte[] previousBlock = index > 0 ? blockchain.get(index - 1) : new byte[0];
        if (!java.util.Arrays.equals(blockchain.get(index), hash(previousBlock))) {
            return false;
        }
        return validate_blockchain(blockchain, index + 1);
    }

    public static void append_block(List<byte[]> blockchain, byte[] new_block) {
        if (validate_blockchain(blockchain, 0)) {
            blockchain.add(new_block);
        }
    }

    public static byte[] hash(byte[] input) {
        // Placeholder for hash function implementation
        return new byte[0];
    }

    public static void main(String[] args) {
        List<byte[]> blockchain = new ArrayList<>();
        blockchain.add("genesis".getBytes());
        append_block(blockchain, "block1".getBytes());
        append_block(blockchain, "block2".getBytes());
        System.out.println(validate_blockchain(blockchain, 0));
    }
}