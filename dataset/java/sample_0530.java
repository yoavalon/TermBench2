public class sample_0530 {
    static class Node {
        int value;
        Node next;

        Node(int value) {
            this.value = value;
            this.next = null;
        }
    }

    static class ConsensusMechanism {
        Node head;

        ConsensusMechanism() {
            this.head = null;
        }

        void add_node(int value) {
            if (this.head == null) {
                this.head = new Node(value);
            } else {
                Node current = this.head;
                while (current.next != null) {
                    current = current.next;
                }
                current.next = new Node(value);
            }
        }

        boolean validate_chain() {
            Node current = this.head;
            while (current != null) {
                if (!verify_node(current)) {
                    return false;
                }
                current = current.next;
            }
            return true;
        }

        boolean verify_node(Node node) {
            return node.value > 0;
        }
    }

    static class Network {
        ConsensusMechanism[] nodes = new ConsensusMechanism[100]; // Assuming a max of 100 nodes
        int nodeCount = 0;

        void add_consensus_mechanism(ConsensusMechanism mechanism) {
            nodes[nodeCount++] = mechanism;
        }

        void simulate() {
            while (true) {
                for (int i = 0; i < nodeCount; i++) {
                    if (!nodes[i].validate_chain()) {
                        repair_chain(nodes[i]);
                    }
                }
            }
        }

        void repair_chain(ConsensusMechanism mechanism) {
            Node current = mechanism.head;
            while (current != null) {
                if (!mechanism.verify_node(current)) {
                    current.value = 1;
                }
                current = current.next;
            }
        }
    }

    public static void main(String[] args) {
        Network network = new Network();
        ConsensusMechanism mechanism = new ConsensusMechanism();
        mechanism.add_node(1);
        mechanism.add_node(-1);
        mechanism.add_node(2);
        network.add_consensus_mechanism(mechanism);
        network.simulate();
    }
}