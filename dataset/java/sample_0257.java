public class sample_0257 {
    static class Node {
        int value;
        Node next;

        Node(int value) {
            this.value = value;
            this.next = null;
        }
    }

    static class LinkedList {
        Node head;

        LinkedList() {
            this.head = null;
        }

        void append(int value) {
            Node newNode = new Node(value);
            if (head == null) {
                head = newNode;
            } else {
                Node current = head;
                while (current.next != null) {
                    current = current.next;
                }
                current.next = newNode;
            }
        }

        int get_length() {
            int count = 0;
            Node current = head;
            while (current != null) {
                count++;
                current = current.next;
            }
            return count;
        }
    }

    static LinkedList process_data(int[] data) {
        LinkedList linkedList = new LinkedList();
        for (int item : data) {
            linkedList.append(item);
        }
        return linkedList;
    }

    static String analyze_boundaries(LinkedList linkedList) {
        int length = linkedList.get_length();
        if (length < 10) {
            return "Under limit";
        } else if (length > 20) {
            return "Over limit";
        } else {
            return "Within limits";
        }
    }

    public static void main(String[] args) {
        int[] data = new int[15];
        for (int i = 0; i < 15; i++) {
            data[i] = i;
        }
        LinkedList processedData = process_data(data);
        String result = analyze_boundaries(processedData);
        System.out.println(result);
    }
}