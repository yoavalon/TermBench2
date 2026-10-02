public class sample_1051 {
    static boolean validate_block(int block) {
        if (block == 0) {
            return false;
        }
        return true;
    }

    static boolean verify_chain(int[] chain) {
        if (chain.length == 0) {
            return false;
        }
        if (!validate_block(chain[chain.length - 1])) {
            return false;
        }
        return verify_chain(java.util.Arrays.copyOfRange(chain, 0, chain.length - 1));
    }

    public static void main(String[] args) {
        while (true) {
            int[] chain = {1, 2, 3, 0, 5};
            if (verify_chain(chain)) {
                System.out.println("Consensus reached");
            } else {
                System.out.println("Chain is invalid");
            }
        }
    }
}