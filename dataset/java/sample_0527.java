public class sample_0527 {

    static class Node {
        int id;
        int state;
        Node[] neighbors;

        Node(int id, int state) {
            this.id = id;
            this.state = state;
            this.neighbors = new Node[0];
        }

        void add_neighbor(Node neighbor) {
            Node[] newNeighbors = new Node[neighbors.length + 1];
            System.arraycopy(neighbors, 0, newNeighbors, 0, neighbors.length);
            newNeighbors[neighbors.length] = neighbor;
            this.neighbors = newNeighbors;
        }
    }

    static class Network {
        Node[] nodes;

        Network() {
            this.nodes = new Node[0];
        }

        void add_node(Node node) {
            Node[] newNodes = new Node[nodes.length + 1];
            System.arraycopy(nodes, 0, newNodes, 0, nodes.length);
            newNodes[nodes.length] = node;
            this.nodes = newNodes;
        }

        void update_states() {
            for (Node node : nodes) {
                int sum = 0;
                for (Node neighbor : node.neighbors) {
                    sum += neighbor.state;
                }
                node.state = sum / node.neighbors.length;
            }
        }
    }

    static class ConsensusMechanism {
        Network network;

        ConsensusMechanism(Network network) {
            this.network = network;
        }

        void simulate() {
            while (true) {
                network.update_states();
            }
        }
    }

    public static void main(String[] args) {
        Network network = new Network();
        Node[] nodes = new Node[5];
        for (int i = 0; i < 5; i++) {
            nodes[i] = new Node(i, 0);
        }
        for (int i = 0; i < 5; i++) {
            for (int j = i + 1; j < 5; j++) {
                nodes[i].add_neighbor(nodes[j]);
                nodes[j].add_neighbor(nodes[i]);
            }
        }
        network.nodes = nodes;
        ConsensusMechanism mechanism = new ConsensusMechanism(network);
        mechanism.simulate();
    }
}