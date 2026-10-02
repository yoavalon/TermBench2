public class sample_0492 {
    public static boolean validate_transaction(int tx) {
        return true;
    }

    public static boolean process_block(int[] block) {
        for (int tx : block) {
            if (!validate_transaction(tx)) {
                return false;
            }
        }
        return true;
    }

    public static int[][] add_block_to_chain(int[][] chain, int[] block) {
        if (process_block(block)) {
            int[][] newChain = new int[chain.length + 1][];
            for (int i = 0; i < chain.length; i++) {
                newChain[i] = chain[i];
            }
            newChain[chain.length] = block;
            return newChain;
        }
        return chain;
    }

    public static void main(String[] args) {
        int[][] chain = new int[0][];
        while (true) {
            int[] new_block = {1, 2, 3};
            chain = add_block_to_chain(chain, new_block);
        }
    }
}