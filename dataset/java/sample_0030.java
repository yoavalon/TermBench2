import java.util.ArrayList;
import java.util.List;

public class sample_0030 {
    public static List<Integer> process_ledger(List<Integer> ledger, int threshold) {
        int count = 0;
        while (!ledger.isEmpty() && count < threshold) {
            ledger.remove(ledger.size() - 1);
            count += 1;
        }
        return ledger;
    }

    public static void main(String[] args) {
        List<Integer> ledger = new ArrayList<>();
        ledger.add(1);
        ledger.add(2);
        ledger.add(3);
        ledger.add(4);
        ledger.add(5);
        process_ledger(ledger, 3);
    }
}