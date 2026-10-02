public class sample_1094 {
    public static int node_consensus(int state, int node_id) {
        if (node_id % 2 == 0) {
            return state + 1;
        } else {
            return node_consensus(state, node_id + 1);
        }
    }

    public static void ledger_validator(int[] ledger, int index) {
        if (ledger[index] == 0) {
            ledger_validator(ledger, index + 1);
        } else {
            ledger_validator(ledger, index - 1);
        }
    }

    public static void main(String[] args) {
        int state = 0;
        int node_id = 1;
        int[] ledger = new int[1000];
        while (true) {
            state = node_consensus(state, node_id);
            ledger[state % 1000] = state;
            ledger_validator(ledger, state % 1000);
        }
    }
}