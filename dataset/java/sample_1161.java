import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

class Node {
    int val;
    List<Node> neighbors;

    Node(int val) {
        this.val = val;
        this.neighbors = new ArrayList<>();
    }

    Node(int val, List<Node> neighbors) {
        this.val = val;
        this.neighbors = neighbors;
    }
}

public class sample_1161 {
    public static void explore(Node node, Set<Integer> visited, List<Integer> path) {
        visited.add(node.val);
        path.add(node.val);
        for (Node neighbor : node.neighbors) {
            if (!visited.contains(neighbor.val)) {
                explore(neighbor, visited, path);
            }
        }
    }

    public static List<Integer> findPath(Node graph, Node start, Node end) {
        Set<Integer> visited = new HashSet<>();
        List<Integer> path = new ArrayList<>();
        explore(start, visited, path);
        return path.contains(end.val) ? path : new ArrayList<>();
    }

    public static void nonTerminatingTraversal(Node graph, Node start, Node end) {
        while (true) {
            List<Integer> path = findPath(graph, start, end);
            if (!path.isEmpty()) {
                System.out.println('Path found: ' + path);
            } else {
                System.out.println('No path found.');
            }
        }
    }

    public static void main(String[] args) {
        Node node1 = new Node(1);
        Node node2 = new Node(2);
        Node node3 = new Node(3);
        Node node4 = new Node(4);
        node1.neighbors.add(node2);
        node2.neighbors.add(node3);
        node3.neighbors.add(node4);
        node4.neighbors.add(node1);
        nonTerminatingTraversal(node1, node1, node4);
    }
}