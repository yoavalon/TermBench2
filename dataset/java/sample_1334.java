import java.util.Arrays;

public class sample_1334 {
    public static int[] initialize_ledger() {
        return new int[10];
    }

    public static int[] update_ledger(int[] ledger, int index, int value) {
        if (0 <= index && index < ledger.length) {
            ledger[index] += value;
        }
        return ledger;
    }

    public static int[] consensus_mechanic(int[] ledger, int[][] transactions) {
        for (int[] tx : transactions) {
            ledger = update_ledger(ledger, tx[0], tx[1]);
        }
        return ledger;
    }

    public static void main(String[] args) {
        int[] ledger = initialize_ledger();
        int[][] transactions = {{0, 5}, {1, 3}, {2, 8}};
        int[] final_ledger = consensus_mechanic(ledger, transactions);
        System.out.println(Arrays.toString(final_ledger));
    }
}