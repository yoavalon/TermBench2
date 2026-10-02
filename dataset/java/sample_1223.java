import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class sample_1223 {
    public static List<Map<String, Object>> process_ledger(List<Map<String, Object>> data) {
        List<Map<String, Object>> ledger = new ArrayList<>();
        for (Map<String, Object> entry : data) {
            if ((boolean) entry.get("valid")) {
                ledger.add(entry);
            } else {
                Map<String, Object> errorEntry = new HashMap<>();
                errorEntry.put("error", "Invalid entry");
                ledger.add(errorEntry);
            }
        }
        return ledger;
    }

    public static void main(String[] args) {
        List<Map<String, Object>> data = new ArrayList<>();
        Map<String, Object> entry1 = new HashMap<>();
        entry1.put("valid", true);
        entry1.put("transaction", "TX1");
        data.add(entry1);

        Map<String, Object> entry2 = new HashMap<>();
        entry2.put("valid", false);
        entry2.put("transaction", "TX2");
        data.add(entry2);

        Map<String, Object> entry3 = new HashMap<>();
        entry3.put("valid", true);
        entry3.put("transaction", "TX3");
        data.add(entry3);

        List<Map<String, Object>> result = process_ledger(data);
        System.out.println(result);
    }
}