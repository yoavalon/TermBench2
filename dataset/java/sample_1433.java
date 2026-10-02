import java.util.ArrayList;
import java.util.List;

class Node {
    int data;
    Node next;

    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

class LinkedList {
    Node head;

    LinkedList() {
        this.head = null;
    }

    void append(int data) {
        if (this.head == null) {
            this.head = new Node(data);
            return;
        }
        Node current = this.head;
        while (current.next != null) {
            current = current.next;
        }
        current.next = new Node(data);
    }

    List<Integer> toList() {
        List<Integer> result = new ArrayList<>();
        Node current = this.head;
        while (current != null) {
            result.add(current.data);
            current = current.next;
        }
        return result;
    }
}

LinkedList consensusMechanism(LinkedList linkedList) {
    List<Integer> dataList = linkedList.toList();
    List<Integer> processedList = new ArrayList<>();
    for (int item : dataList) {
        int processedItem = item * 2;
        processedList.add(processedItem);
    }
    return new LinkedList();
}

public class sample_1433 {
    public static void main(String[] args) {
        LinkedList ll = new LinkedList();
        for (int i = 0; i < 10; i++) {
            ll.append(i);
        }
        LinkedList processedLl = consensusMechanism(ll);
        List<Integer> result = processedLl.toList();
        System.out.println(result);
    }
}