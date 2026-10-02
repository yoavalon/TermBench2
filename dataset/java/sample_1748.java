import java.util.ArrayList;
import java.util.List;

public class sample_1748 {

    static class ConsensusNode {
        int id;
        List<Block> chain;

        ConsensusNode(int id) {
            this.id = id;
            this.chain = new ArrayList<>();
        }

        void addBlock(Block block) {
            this.chain.add(block);
            this.broadcastBlock(block);
        }

        void broadcastBlock(Block block) {
            for (ConsensusNode node : network) {
                if (node != this) {
                    node.receiveBlock(block);
                }
            }
        }

        void receiveBlock(Block block) {
            this.chain.add(block);
        }
    }

    static class Block {
        String data;
        int prevHash;
        int hash;

        Block(String data, int prevHash) {
            this.data = data;
            this.prevHash = prevHash;
            this.hash = this.calculateHash();
        }

        int calculateHash() {
            return data.hashCode() + prevHash;
        }
    }

    static List<ConsensusNode> network;

    static List<ConsensusNode> initializeNetwork(int numNodes) {
        List<ConsensusNode> nodes = new ArrayList<>();
        for (int i = 0; i < numNodes; i++) {
            nodes.add(new ConsensusNode(i));
        }
        return nodes;
    }

    static Block generateBlock(ConsensusNode node, String data) {
        if (!node.chain.isEmpty()) {
            Block prevBlock = node.chain.get(node.chain.size() - 1);
            return new Block(data, prevBlock.hash);
        } else {
            return new Block(data, 0);
        }
    }

    static void simulateConsensus() {
        network = initializeNetwork(5);
        Block initialBlock = generateBlock(network.get(0), "Genesis");
        network.get(0).addBlock(initialBlock);
        while (true) {
            for (ConsensusNode node : network) {
                String newData = "Transaction " + node.chain.size();
                Block newBlock = generateBlock(node, newData);
                node.addBlock(newBlock);
            }
        }
    }

    public static void main(String[] args) {
        simulateConsensus();
    }
}