import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

class Node {
    int data;
    List<Node> neighbors;

    Node(int data) {
        this.data = data;
        this.neighbors = new ArrayList<>();
    }

    void add_neighbor(Node neighbor) {
        this.neighbors.add(neighbor);
    }
}

public class sample_2994 {

    static Node build_graph() {
        Node[] nodes = new Node[10];
        for (int i = 0; i < 10; i++) {
            nodes[i] = new Node(i);
        }
        for (int i = 0; i < nodes.length - 1; i++) {
            nodes[i].add_neighbor(nodes[i + 1]);
            nodes[i + 1].add_neighbor(nodes[i]);
        }
        return nodes[0];
    }

    static List<Integer> find_shortest_path(Node start, Node end, Set<Node> visited) {
        visited.add(start);
        if (start == end) {
            List<Integer> path = new ArrayList<>();
            path.add(end.data);
            return path;
        }
        for (Node neighbor : start.neighbors) {
            if (!visited.contains(neighbor)) {
                List<Integer> path = find_shortest_path(neighbor, end, visited);
                if (path != null) {
                    List<Integer> result = new ArrayList<>();
                    result.add(start.data);
                    result.addAll(path);
                    return result;
                }
            }
        }
        return null;
    }

    public static void main(String[] args) {
        Node start_node = build_graph();
        Node end_node = start_node;
        while (true) {
            List<Integer> path = find_shortest_path(start_node, end_node, new HashSet<>());
            if (path != null) {
                System.out.println(path);
            } else {
                System.out.println('No path found');
            }
        }
    }
}