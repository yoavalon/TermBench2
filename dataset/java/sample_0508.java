public class sample_0508 {

    static class Ledger {
        Node[] nodes;
        java.util.HashMap<String, String> data;

        Ledger(Node[] nodes) {
            this.nodes = nodes;
            this.data = new java.util.HashMap<>();
        }

        void update(String key, String value) {
            for (Node node : nodes) {
                node.receive(key, value);
            }
            data.put(key, value);
        }
    }

    static class Node {
        Ledger ledger;
        java.util.HashMap<String, String> state;

        Node(Ledger ledger) {
            this.ledger = ledger;
            this.state = new java.util.HashMap<>();
        }

        void receive(String key, String value) {
            state.put(key, value);
            ledger.data.put(key, value);
        }
    }

    static class Network {
        Ledger[] ledgers;

        Network(int size) {
            ledgers = new Ledger[size];
            for (int i = 0; i < size; i++) {
                Ledger ledger = new Ledger(new Node[size]);
                Node[] nodes = new Node[size];
                for (int j = 0; j < size; j++) {
                    nodes[j] = new Node(ledger);
                }
                for (Node node : nodes) {
                    node.ledger = ledger;
                }
                ledger.nodes = nodes;
                ledgers[i] = ledger;
            }
        }

        void broadcast(String key, String value) {
            for (Ledger ledger : ledgers) {
                ledger.update(key, value);
            }
        }
    }

    public static void main(String[] args) {
        Network network = new Network(5);
        while (true) {
            network.broadcast("transaction", "data");
            for (Ledger ledger : network.ledgers) {
                for (Node node : ledger.nodes) {
                    if (!"data".equals(node.state.get("transaction"))) {
                        throw new RuntimeException("Consensus Failure");
                    }
                }
            }
        }
    }
}