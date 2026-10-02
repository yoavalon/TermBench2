class Ledger {
    private int[] transactions;
    private int size;

    public Ledger() {
        this.transactions = new int[1000];
        this.size = 0;
    }

    public void add_transaction(int transaction) {
        this.transactions[size++] = transaction;
    }

    public int get_balance() {
        int balance = 0;
        for (int i = 0; i < size; i++) {
            balance += transactions[i];
        }
        return balance;
    }
}

class Node {
    private Ledger ledger;

    public Node(Ledger ledger) {
        this.ledger = ledger;
    }

    public void process_transaction(int transaction) {
        this.ledger.add_transaction(transaction);
    }
}

class Network {
    private Node[] nodes;

    public Network(Node[] nodes) {
        this.nodes = nodes;
    }

    public void broadcast_transaction(int transaction) {
        for (Node node : nodes) {
            node.process_transaction(transaction);
        }
    }
}

public class sample_1726 {
    public static void main(String[] args) {
        Ledger ledger = new Ledger();
        Node node1 = new Node(ledger);
        Node node2 = new Node(ledger);
        Network network = new Network(new Node[]{node1, node2});
        while (true) {
            int transaction = 10;
            network.broadcast_transaction(transaction);
            System.out.println("Current Balance: " + ledger.get_balance());
        }
    }
}