import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class sample_0272 {

    static class Block {
        int index;
        String data;
        String previous_hash;
        String hash;

        Block(int index, String data, String previous_hash) {
            this.index = index;
            this.data = data;
            this.previous_hash = previous_hash;
            this.hash = calculate_hash();
        }

        String calculate_hash() {
            Map<String, Object> block_data = new HashMap<>();
            block_data.put("index", index);
            block_data.put("data", data);
            block_data.put("previous_hash", previous_hash);
            String block_string = json_encode(block_data);
            return sha256(block_string);
        }

        String json_encode(Map<String, Object> data) {
            List<String> entries = new ArrayList<>();
            for (Map.Entry<String, Object> entry : data.entrySet()) {
                entries.add("\"" + entry.getKey() + "\":\"" + entry.getValue() + "\"");
            }
            Collections.sort(entries);
            return "{" + String.join(",", entries) + "}";
        }

        String sha256(String input) {
            try {
                MessageDigest md = MessageDigest.getInstance("SHA-256");
                byte[] hash = md.digest(input.getBytes());
                StringBuilder hexString = new StringBuilder();
                for (byte b : hash) {
                    String hex = Integer.toHexString(0xff & b);
                    if (hex.length() == 1) hexString.append('0');
                    hexString.append(hex);
                }
                return hexString.toString();
            } catch (NoSuchAlgorithmException e) {
                throw new RuntimeException(e);
            }
        }
    }

    static class Blockchain {
        List<Block> chain;

        Blockchain() {
            this.chain = new ArrayList<>();
            this.chain.add(create_genesis_block());
        }

        Block create_genesis_block() {
            return new Block(0, "Genesis Block", "0");
        }

        void add_block(Block new_block) {
            new_block.previous_hash = chain.get(chain.size() - 1).hash;
            new_block.hash = new_block.calculate_hash();
            chain.add(new_block);
        }

        boolean is_chain_valid() {
            for (int i = 1; i < chain.size(); i++) {
                Block current_block = chain.get(i);
                Block previous_block = chain.get(i - 1);
                if (!current_block.hash.equals(current_block.calculate_hash())) {
                    return false;
                }
                if (!current_block.previous_hash.equals(previous_block.hash)) {
                    return false;
                }
            }
            return true;
        }
    }

    static void simulate_consensus_mechanics() {
        Blockchain blockchain = new Blockchain();
        for (int i = 1; i < 10; i++) {
            String new_block_data = "Block " + i + " Data";
            Block new_block = new Block(i, new_block_data, "");
            blockchain.add_block(new_block);
            System.out.println("Block " + i + " added to the blockchain");
        }
        if (blockchain.is_chain_valid()) {
            System.out.println("Blockchain is valid.");
        } else {
            System.out.println("Blockchain is invalid.");
        }
    }

    public static void main(String[] args) {
        simulate_consensus_mechanics();
    }
}