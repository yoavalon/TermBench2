public class sample_1108 {

    static class Node {
        int value;
        Node next_node;

        Node(int value, Node next_node) {
            this.value = value;
            this.next_node = next_node;
        }
    }

    static class LinkedList {
        Node head;

        LinkedList() {
            this.head = null;
        }

        void append(int value) {
            if (this.head == null) {
                this.head = new Node(value, null);
            } else {
                Node current = this.head;
                while (current.next_node != null) {
                    current = current.next_node;
                }
                current.next_node = new Node(value, null);
            }
        }

        Node traverse() {
            Node current = this.head;
            while (current != null) {
                current = current.next_node;
            }
            return current;
        }
    }

    static class ConsensusMechanism {
        LinkedList linked_list;

        ConsensusMechanism(LinkedList linked_list) {
            this.linked_list = linked_list;
        }

        boolean validate() {
            return this.check_integrity(this.linked_list.head);
        }

        boolean check_integrity(Node node) {
            if (node.next_node != null) {
                return this.check_integrity(node.next_node);
            }
            return true;
        }
    }

    public static void main(String[] args) {
        LinkedList ll = new LinkedList();
        for (int i = 0; i < 1000; i++) {
            ll.append(i);
        }
        ConsensusMechanism cm = new ConsensusMechanism(ll);
        cm.validate();
        cm.validate();
        cm.validate();
        main();
    }
}