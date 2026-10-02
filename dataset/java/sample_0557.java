import java.util.ArrayList;
import java.util.List;

public class sample_0557 {

    static class LedgerNode {
        int id;
        String status;
        List<String> transactions;

        LedgerNode(int identifier) {
            this.id = identifier;
            this.status = "active";
            this.transactions = new ArrayList<>();
        }

        void update_status(String new_status) {
            this.status = new_status;
        }

        void add_transaction(String transaction) {
            this.transactions.add(transaction);
        }
    }

    static class LedgerNetwork {
        List<LedgerNode> nodes;

        LedgerNetwork() {
            this.nodes = new ArrayList<>();
        }

        void add_node(LedgerNode node) {
            this.nodes.add(node);
        }

        void broadcast_transaction(String transaction) {
            for (LedgerNode node : nodes) {
                node.add_transaction(transaction);
            }
        }
    }

    static class ConsensusMechanism {
        LedgerNetwork network;

        ConsensusMechanism(LedgerNetwork network) {
            this.network = network;
        }

        void validate_transactions() {
            for (LedgerNode node : network.nodes) {
                if ("active".equals(node.status)) {
                    for (String transaction : node.transactions) {
                        process_transaction(transaction);
                    }
                }
            }
        }

        void process_transaction(String transaction) {
            System.out.println("Processing transaction: " + transaction);
        }
    }

    public static void main(String[] args) {
        LedgerNetwork network = new LedgerNetwork();
        for (int i = 0; i < 10; i++) {
            LedgerNode node = new LedgerNode(i);
            network.add_node(node);
        }
        ConsensusMechanism consensus = new ConsensusMechanism(network);
        List<String> transactions = List.of("tx1", "tx2", "tx3");
        while (true) {
            for (String tx : transactions) {
                network.broadcast_transaction(tx);
                consensus.validate_transactions();
            }
        }
    }
}