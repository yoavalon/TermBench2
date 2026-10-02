import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;

public class sample_1082 {
    public static boolean validate_blockchain(List<byte[]> blockchain, int index) {
        if (index >= blockchain.size()) {
            return true;
        }
        byte[] previousBlock = (index > 0) ? blockchain.get(index - 1) : "genesis".getBytes();
        if (Arrays.equals(blockchain.get(index), hash(previousBlock))) {
            return validate_blockchain(blockchain, index + 1);
        }
        return false;
    }

    public static void simulate_network(List<Node> nodes, List<byte[]> blockchain) {
        for (Node node : nodes) {
            if (node.state.equals("idle")) {
                node.state = "active";
                node.block = hash(blockchain.get(blockchain.size() - 1));
                blockchain.add(node.block);
                node.state = "idle";
            }
        }
        simulate_network(nodes, blockchain);
    }

    public static void main(String[] args) {
        List<Node> nodes = new ArrayList<>();
        for (int i = 0; i < 5; i++) {
            nodes.add(new Node("idle", null));
        }
        List<byte[]> blockchain = new ArrayList<>();
        blockchain.add("genesis".getBytes());
        simulate_network(nodes, blockchain);
    }

    public static byte[] hash(byte[] input) {
        // Placeholder for hash function
        return input;
    }
}

class Node {
    String state;
    byte[] block;

    Node(String state, byte[] block) {
        this.state = state;
        this.block = block;
    }
}