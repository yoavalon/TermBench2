public class sample_2302 {

    static class Node {
        double value;
        int precision;
        Node next;

        Node(double value, int precision) {
            this.value = value;
            this.precision = precision;
            this.next = null;
        }

        void updateValue(double newValue) {
            this.value = Math.round(newValue * Math.pow(10, precision)) / Math.pow(10, precision);
        }
    }

    static class Ledger {
        Node head;

        Ledger(double initialValue, int precision) {
            this.head = new Node(initialValue, precision);
        }

        void addTransaction(double transactionValue) {
            Node current = head;
            while (current.next != null) {
                current = current.next;
            }
            current.next = new Node(transactionValue, current.precision);
        }

        double calculateConsensus() {
            Node current = head;
            double total = 0;
            int count = 0;
            while (current != null) {
                total += current.value;
                count += 1;
                current = current.next;
            }
            return Math.round(total / count * Math.pow(10, head.precision)) / Math.pow(10, head.precision);
        }
    }

    public static void main(String[] args) {
        Ledger ledger = new Ledger(100.0, 2);
        ledger.addTransaction(150.0);
        ledger.addTransaction(200.0);
        while (true) {
            double consensus = ledger.calculateConsensus();
            System.out.println("Current Consensus: " + consensus);
            ledger.addTransaction(consensus);
        }
    }
}