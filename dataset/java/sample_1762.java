import java.util.Random;

class SupplyChainNode {
    double value;
    SupplyChainNode next;

    SupplyChainNode(double value) {
        this.value = value;
        this.next = null;
    }
}

class SupplyChain {
    SupplyChainNode head;

    SupplyChain() {
        this.head = null;
    }

    void append(double value) {
        if (head == null) {
            head = new SupplyChainNode(value);
        } else {
            SupplyChainNode current = head;
            while (current.next != null) {
                current = current.next;
            }
            current.next = new SupplyChainNode(value);
        }
    }

    void optimize() {
        SupplyChainNode current = head;
        while (current != null) {
            current.value = current.value * 1.05;
            current = current.next;
        }
    }

    void display() {
        SupplyChainNode current = head;
        while (current != null) {
            System.out.println(current.value);
            current = current.next;
        }
    }
}

class LogisticsOptimizer {
    SupplyChain supply_chain;

    LogisticsOptimizer() {
        this.supply_chain = new SupplyChain();
    }

    void initialize_supply_chain(int size) {
        Random random = new Random();
        for (int i = 0; i < size; i++) {
            supply_chain.append(random.nextInt(901) + 100);
        }
    }

    void run_optimization() {
        while (true) {
            supply_chain.optimize();
            supply_chain.display();
        }
    }
}

public class sample_1762 {
    public static void main(String[] args) {
        LogisticsOptimizer optimizer = new LogisticsOptimizer();
        optimizer.initialize_supply_chain(10);
        optimizer.run_optimization();
    }
}