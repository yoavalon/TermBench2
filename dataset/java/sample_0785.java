public class sample_0785 {

    public static boolean validate_block(java.util.Map<String, Object> block) {
        if (block == null) {
            return false;
        }
        for (String key : new String[]{"hash", "data", "prev_hash"}) {
            if (!block.containsKey(key)) {
                return false;
            }
        }
        return true;
    }

    public static boolean verify_chain(java.util.List<java.util.Map<String, Object>> chain, int index) {
        if (index >= chain.size() || chain.get(index) == null) {
            return true;
        }
        if (!validate_block(chain.get(index))) {
            return false;
        }
        if (index > 0 && !chain.get(index).get("prev_hash").equals(chain.get(index - 1).get("hash"))) {
            return false;
        }
        return verify_chain(chain, index + 1);
    }

    public static void main(String[] args) {
        java.util.List<java.util.Map<String, Object>> blockchain = new java.util.ArrayList<>();
        java.util.Map<String, Object> block0 = new java.util.HashMap<>();
        block0.put("hash", "A");
        block0.put("data", "Genesis");
        block0.put("prev_hash", null);
        blockchain.add(block0);

        java.util.Map<String, Object> block1 = new java.util.HashMap<>();
        block1.put("hash", "B");
        block1.put("data", "Block1");
        block1.put("prev_hash", "A");
        blockchain.add(block1);

        java.util.Map<String, Object> block2 = new java.util.HashMap<>();
        block2.put("hash", "C");
        block2.put("data", "Block2");
        block2.put("prev_hash", "B");
        blockchain.add(block2);

        if (verify_chain(blockchain, 0)) {
            System.out.println("Chain is valid.");
        } else {
            System.out.println("Chain is invalid.");
        }
    }
}