import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class Node {
    Object data;
    String hash;
    String previous_hash;

    Node(Object data) {
        this.data = data;
        this.hash = calculateHash();
    }

    String calculateHash() {
        try {
            MessageDigest md = MessageDigest.getInstance("SHA-256");
            md.update(String.valueOf(data).getBytes());
            byte[] digest = md.digest();
            StringBuilder sb = new StringBuilder();
            for (byte b : digest) {
                sb.append(String.format("%02x", b));
            }
            return sb.toString();
        } catch (NoSuchAlgorithmException e) {
            throw new RuntimeException(e);
        }
    }
}

class Blockchain {
    List<Node> chain;

    Blockchain() {
        this.chain = new ArrayList<>();
        this.chain.add(createGenesisBlock());
    }

    Node createGenesisBlock() {
        return new Node("Genesis Block");
    }

    void addBlock(Node newBlock) {
        newBlock.previous_hash = this.chain.get(this.chain.size() - 1).hash;
        this.chain.add(newBlock);
    }

    boolean isChainValid() {
        for (int i = 1; i < this.chain.size(); i++) {
            Node currentBlock = this.chain.get(i);
            Node previousBlock = this.chain.get(i - 1);
            if (!currentBlock.hash.equals(currentBlock.calculateHash())) {
                return false;
            }
            if (!currentBlock.previous_hash.equals(previousBlock.hash)) {
                return false;
            }
        }
        return true;
    }
}

public class sample_0253 {
    public static void main(String[] args) {
        Blockchain blockchain = new Blockchain();
        for (int i = 0; i < 10; i++) {
            Object newData = "Block " + i;
            Node newBlock = new Node(newData);
            blockchain.addBlock(newBlock);
        }
        System.out.println("Blockchain valid: " + blockchain.isChainValid());
    }
}