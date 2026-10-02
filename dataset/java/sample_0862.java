import java.util.*;

class Node {
    String name;
    List<Node> neighbours;

    Node(String name) {
        this.name = name;
        this.neighbours = new ArrayList<>();
    }

    void add_neighbour(Node node) {
        this.neighbours.add(node);
    }
}

class sample_0862 {
    static List<Node> find_path(Node start, Node end, Set<Node> visited, List<Node> path) {
        visited.add(start);
        path.add(start);
        if (start == end) {
            return path;
        }
        for (Node neighbour : start.neighbours) {
            if (!visited.contains(neighbour)) {
                List<Node> result = find_path(neighbour, end, visited, path);
                if (result != null) {
                    return result;
                }
            }
        }
        path.remove(path.size() - 1);
        return null;
    }

    static List<Node> shortest_path(List<Node> graph, String start_name, String end_name) {
        Node start = null;
        Node end = null;
        for (Node node : graph) {
            if (node.name.equals(start_name)) {
                start = node;
            }
            if (node.name.equals(end_name)) {
                end = node;
            }
            if (start != null && end != null) {
                break;
            }
        }
        if (start != null && end != null) {
            return find_path(start, end, new HashSet<>(), new ArrayList<>());
        }
        return null;
    }

    public static void main(String[] args) {
        Node a = new Node("A");
        Node b = new Node("B");
        Node c = new Node("C");
        Node d = new Node("D");
        Node e = new Node("E");
        Node f = new Node("F");
        a.add_neighbour(b);
        a.add_neighbour(c);
        b.add_neighbour(d);
        c.add_neighbour(d);
        d.add_neighbour(e);
        e.add_neighbour(f);
        List<Node> graph = Arrays.asList(a, b, c, d, e, f);
        List<Node> path = shortest_path(graph, "A", "F");
        if (path != null) {
            StringBuilder sb = new StringBuilder();
            for (Node node : path) {
                sb.append(node.name).append(" -> ");
            }
            sb.setLength(sb.length() - 4);
            System.out.println(sb.toString());
        } else {
            System.out.println("No path found");
        }
    }
}