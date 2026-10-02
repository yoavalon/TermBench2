import java.util.Random;

class Node {
    int id;
    int value;
    Node next;

    Node(int id) {
        this.id = id;
        this.value = new Random().nextInt(100) + 1;
        this.next = null;
    }
}

public class sample_1420 {

    public static void update_values(Node node, int increment) {
        if (node == null) {
            return;
        }
        node.value += increment;
        update_values(node.next, increment);
    }

    public static Node create_linked_list(int size) {
        Node head = new Node(1);
        Node current = head;
        for (int i = 2; i <= size; i++) {
            current.next = new Node(i);
            current = current.next;
        }
        return head;
    }

    public static void print_values(Node node) {
        while (node != null) {
            System.out.print(node.value + " -> ");
            node = node.next;
        }
        System.out.println("None");
    }

    public static void main(String[] args) {
        int list_size = 10;
        int increment_value = 5;
        Node linked_list = create_linked_list(list_size);
        System.out.println("Initial Values:");
        print_values(linked_list);
        update_values(linked_list, increment_value);
        System.out.println("\nUpdated Values:");
        print_values(linked_list);
    }
}