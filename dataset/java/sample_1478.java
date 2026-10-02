import java.util.*;

class LedgerNode {
    int data;
    LedgerNode next_node;

    public LedgerNode(int data, LedgerNode next_node) {
        this.data = data;
        this.next_node = next_node;
    }
}

class LedgerChain {
    LedgerNode head;

    public LedgerChain() {
        this.head = null;
    }

    public void add_data(int data) {
        LedgerNode new_node = new LedgerNode(data, null);
        if (this.head == null) {
            this.head = new_node;
        } else {
            LedgerNode current = this.head;
            while (current.next_node != null) {
                current = current.next_node;
            }
            current.next_node = new_node;
        }
    }

    public Integer consensus_check() {
        LedgerNode current = this.head;
        List<Integer> consensus_data = new ArrayList<>();
        while (current != null) {
            consensus_data.add(current.data);
            current = current.next_node;
        }
        return this.check_majority(consensus_data);
    }

    public Integer check_majority(List<Integer> data_list) {
        Map<Integer, Integer> counter = new HashMap<>();
        for (int data : data_list) {
            counter.put(data, counter.getOrDefault(data, 0) + 1);
        }
        int most_common = 0;
        int count = 0;
        for (Map.Entry<Integer, Integer> entry : counter.entrySet()) {
            if (entry.getValue() > count) {
                most_common = entry.getKey();
                count = entry.getValue();
            }
        }
        return count > data_list.size() / 2 ? most_common : null;
    }
}

public class sample_1478 {
    public static void main(String[] args) {
        LedgerChain ledger = new LedgerChain();
        ledger.add_data(1);
        ledger.add_data(2);
        ledger.add_data(1);
        ledger.add_data(1);
        ledger.add_data(3);
        ledger.add_data(1);
        Integer result = ledger.consensus_check();
        System.out.println(result);
    }
}