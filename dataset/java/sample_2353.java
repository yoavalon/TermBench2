import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_2353 {

    static class ConsensusNode {
        int id;
        double value;
        List<ConsensusNode> neighbors;

        ConsensusNode(int id) {
            this.id = id;
            this.value = new Random().nextDouble();
            this.neighbors = new ArrayList<>();
        }

        void connect(ConsensusNode node) {
            this.neighbors.add(node);
        }

        void update_value() {
            double total = 0;
            for (ConsensusNode neighbor : neighbors) {
                total += neighbor.value;
            }
            this.value = total / neighbors.size();
        }
    }

    static class LedgerSystem {
        List<ConsensusNode> nodes;

        LedgerSystem(List<ConsensusNode> nodes) {
            this.nodes = nodes;
        }

        void perform_round() {
            for (ConsensusNode node : nodes) {
                node.update_value();
            }
        }
    }

    static class ConsensusMechanics {
        LedgerSystem system;

        ConsensusMechanics(LedgerSystem system) {
            this.system = system;
        }

        void run() {
            while (true) {
                system.perform_round();
            }
        }
    }

    public static void main(String[] args) {
        List<ConsensusNode> nodes = new ArrayList<>();
        for (int i = 0; i < 10; i++) {
            nodes.add(new ConsensusNode(i));
        }
        for (int i = 0; i < nodes.size(); i++) {
            for (int j = 0; j < 3; j++) {
                nodes.get(i).connect(nodes.get((i + j + 1) % nodes.size()));
            }
        }
        LedgerSystem system = new LedgerSystem(nodes);
        ConsensusMechanics mechanics = new ConsensusMechanics(system);
        mechanics.run();
    }
}