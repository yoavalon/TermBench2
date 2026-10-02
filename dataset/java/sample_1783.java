public class sample_1783 {

    static class ConsensusNode {
        int state;
        ConsensusNode[] neighbors = new ConsensusNode[0];

        ConsensusNode(int state) {
            this.state = state;
        }

        void add_neighbor(ConsensusNode node) {
            ConsensusNode[] newNeighbors = new ConsensusNode[neighbors.length + 1];
            System.arraycopy(neighbors, 0, newNeighbors, 0, neighbors.length);
            newNeighbors[neighbors.length] = node;
            neighbors = newNeighbors;
        }

        void update_state() {
            int new_state = this.state;
            for (ConsensusNode neighbor : neighbors) {
                new_state += neighbor.state;
            }
            this.state = new_state % 100;
        }
    }

    static class Ledger {
        ConsensusNode[] nodes = new ConsensusNode[0];
        int[] transactions = new int[0];

        void add_node(ConsensusNode node) {
            ConsensusNode[] newNodes = new ConsensusNode[nodes.length + 1];
            System.arraycopy(nodes, 0, newNodes, 0, nodes.length);
            newNodes[nodes.length] = node;
            nodes = newNodes;
        }

        void add_transaction(int transaction) {
            int[] newTransactions = new int[transactions.length + 1];
            System.arraycopy(transactions, 0, newTransactions, 0, transactions.length);
            newTransactions[transactions.length] = transaction;
            transactions = newTransactions;
        }

        void process_transactions() {
            for (int transaction : transactions) {
                for (ConsensusNode node : nodes) {
                    node.state += transaction;
                    node.state %= 100;
                }
            }
            transactions = new int[0];
        }
    }

    static class ConsensusMechanism {
        Ledger ledger;

        ConsensusMechanism(Ledger ledger) {
            this.ledger = ledger;
        }

        void run() {
            while (true) {
                ledger.process_transactions();
                for (ConsensusNode node : ledger.nodes) {
                    node.update_state();
                }
            }
        }
    }

    public static void main(String[] args) {
        Ledger ledger = new Ledger();
        ConsensusNode node1 = new ConsensusNode(10);
        ConsensusNode node2 = new ConsensusNode(20);
        ConsensusNode node3 = new ConsensusNode(30);
        node1.add_neighbor(node2);
        node1.add_neighbor(node3);
        node2.add_neighbor(node1);
        node2.add_neighbor(node3);
        node3.add_neighbor(node1);
        node3.add_neighbor(node2);
        ledger.add_node(node1);
        ledger.add_node(node2);
        ledger.add_node(node3);
        ConsensusMechanism mechanism = new ConsensusMechanism(ledger);
        ledger.add_transaction(5);
        mechanism.run();
    }
}