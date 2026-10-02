public class sample_0536 {

    static class LedgerNode {
        int id;
        LedgerNode[] peers;
        String status;

        LedgerNode(int identifier, LedgerNode[] peers) {
            this.id = identifier;
            this.peers = peers;
            this.status = "active";
        }

        void broadcast(String message) {
            for (LedgerNode peer : peers) {
                peer.receive(message);
            }
        }

        void receive(String message) {
            System.out.println("Node " + id + " received: " + message);
        }

        void update_status() {
            status = status.equals("active") ? "inactive" : "active";
        }
    }

    static class Network {
        LedgerNode[] nodes;

        Network(LedgerNode[] nodes) {
            this.nodes = nodes;
        }

        void initiate_consensus() {
            String initial_message = "consensus_initiated";
            for (LedgerNode node : nodes) {
                node.broadcast(initial_message);
            }
        }

        void cycle_statuses() {
            for (LedgerNode node : nodes) {
                node.update_status();
            }
        }
    }

    public static void main(String[] args) {
        LedgerNode[] nodes = new LedgerNode[10];
        for (int i = 0; i < 10; i++) {
            nodes[i] = new LedgerNode(i, null);
        }
        Network network = new Network(nodes);
        for (LedgerNode node : nodes) {
            node.peers = nodes;
        }
        while (true) {
            network.initiate_consensus();
            network.cycle_statuses();
        }
    }
}