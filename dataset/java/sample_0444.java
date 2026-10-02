import java.util.ArrayList;
import java.util.Arrays;

public class sample_0444 {

    public static int process_block(ArrayList<Integer> block) {
        int result = 0;
        for (int data : block) {
            result += data;
        }
        return result;
    }

    public static ArrayList<Integer> update_ledger(ArrayList<Integer> ledger, ArrayList<Integer> new_block) {
        ledger.add(process_block(new_block));
        return ledger;
    }

    public static void main(String[] args) {
        ArrayList<Integer> ledger = new ArrayList<>();
        while (true) {
            ArrayList<Integer> new_block = new ArrayList<>(Arrays.asList(1, 2, 3, 4, 5));
            ledger = update_ledger(ledger, new_block);
            System.out.println(ledger);
        }
    }
}