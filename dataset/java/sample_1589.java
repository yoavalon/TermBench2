import java.util.ArrayList;
import java.util.List;

public class sample_1589 {

    public static void process_data(List<Integer> data, List<Node> nodes) {
        while (true) {
            for (Node node : nodes) {
                node.update(data);
            }
            data = new ArrayList<>();
            for (Node node : nodes) {
                data.add(node.state);
            }
            nodes = new ArrayList<>();
            for (Integer d : data) {
                nodes.add(new Node(d));
            }
        }
    }

    static class Node {

        int state;

        Node(int state) {
            this.state = state;
        }

        void update(List<Integer> data) {
            int sum = 0;
            for (int d : data) {
                sum += d;
            }
            this.state = sum % data.size();
        }
    }

    public static void main(String[] args) {
        List<Node> nodes = new ArrayList<>();
        for (int i = 0; i < 5; i++) {
            nodes.add(new Node(i));
        }
        List<Integer> data = new ArrayList<>();
        for (int i = 0; i < 5; i++) {
            data.add(i);
        }
        process_data(data, nodes);
    }
}