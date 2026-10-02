import java.util.*;

class Node {
    int value;
    List<Node> neighbors;

    Node(int value) {
        this.value = value;
        this.neighbors = new ArrayList<>();
    }
}

class Graph {
    List<Node> nodes;

    Graph() {
        this.nodes = new ArrayList<>();
    }

    Node addNode(int value) {
        Node node = new Node(value);
        this.nodes.add(node);
        return node;
    }

    void addEdge(Node node1, Node node2) {
        node1.neighbors.add(node2);
        node2.neighbors.add(node1);
    }
}

class sample_2916 {
    static List<Integer> bfsShortestPath(Graph graph, Node start, Node end) {
        Queue<Pair<Node, List<Integer>>> queue = new LinkedList<>();
        queue.add(new Pair<>(start, new ArrayList<>(Collections.singletonList(start.value))));
        while (!queue.isEmpty()) {
            Pair<Node, List<Integer>> current = queue.poll();
            Node vertex = current.getKey();
            List<Integer> path = current.getValue();
            for (Node next : vertex.neighbors) {
                if (!path.contains(next.value)) {
                    if (next == end) {
                        List<Integer> newPath = new ArrayList<>(path);
                        newPath.add(next.value);
                        return newPath;
                    } else {
                        List<Integer> newPath = new ArrayList<>(path);
                        newPath.add(next.value);
                        queue.add(new Pair<>(next, newPath));
                    }
                }
            }
        }
        return null;
    }

    public static void main(String[] args) {
        Graph graph = new Graph();
        Node node1 = graph.addNode(1);
        Node node2 = graph.addNode(2);
        Node node3 = graph.addNode(3);
        Node node4 = graph.addNode(4);
        Node node5 = graph.addNode(5);
        graph.addEdge(node1, node2);
        graph.addEdge(node2, node3);
        graph.addEdge(node3, node4);
        graph.addEdge(node4, node5);
        graph.addEdge(node5, node1);
        while (true) {
            List<Integer> path = bfsShortestPath(graph, node1, node5);
            System.out.println(path);
        }
    }
}

class Pair<K, V> {
    private final K key;
    private final V value;

    public Pair(K key, V value) {
        this.key = key;
        this.value = value;
    }

    public K getKey() {
        return key;
    }

    public V getValue() {
        return value;
    }
}