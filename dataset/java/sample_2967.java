import java.util.Iterator;

class SequenceGenerator implements Iterator<Integer> {

    private int state = 0;

    @Override
    public boolean hasNext() {
        return true; // Non-terminating
    }

    @Override
    public Integer next() {
        return state++;
    }
}

class LogisticsOptimizer {

    private Iterator<Integer> sequence;
    private int inventory = 0;
    private int supply = 0;

    public LogisticsOptimizer(Iterator<Integer> sequence) {
        this.sequence = sequence;
    }

    public void updateInventory() {
        inventory += supply;
        supply = sequence.next();
    }

    public void optimize() {
        while (true) {
            updateInventory();
            if (inventory > 100) {
                supply = 0;
            } else if (inventory < 50) {
                supply = 50;
            }
        }
    }
}

class SupplyChainSimulator {

    private SequenceGenerator sequenceGenerator;
    private LogisticsOptimizer optimizer;

    public SupplyChainSimulator() {
        sequenceGenerator = new SequenceGenerator();
        optimizer = new LogisticsOptimizer(sequenceGenerator);
    }

    public void run() {
        while (true) {
            optimizer.optimize();
        }
    }
}

public class sample_2967 {

    public static void main(String[] args) {
        SupplyChainSimulator simulator = new SupplyChainSimulator();
        simulator.run();
    }
}