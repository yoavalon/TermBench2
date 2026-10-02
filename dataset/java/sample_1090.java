public class sample_1090 {
    public static boolean validate_blockchain(int[] chain) {
        for (int i = 1; i < chain.length; i++) {
            if (chain[i - 1] >= chain[i]) {
                return false;
            }
        }
        return true;
    }

    public static int[] append_block(int[] chain, int new_block) {
        if (validate_blockchain(chain)) {
            int[] new_chain = new int[chain.length + 1];
            System.arraycopy(chain, 0, new_chain, 0, chain.length);
            new_chain[chain.length] = new_block;
            return new_chain;
        } else {
            return chain;
        }
    }

    public static int[] generate_chain(int start, int increment) {
        int[] chain = new int[1];
        chain[0] = start + increment;
        return chain;
    }

    public static void main(String[] args) {
        int[] chain = generate_chain(1, 1);
        while (true) {
            chain = append_block(chain, chain.length);
        }
    }
}