import java.util.*;

class Graph {
    private Map<String, List<Pair<String, Integer>>> nodes;

    public Graph() {
        nodes = new HashMap<>();
    }

    public void addNode(String node) {
        nodes.put(node, new ArrayList<>());
    }

    public void addEdge(String node1, String node2, int weight) {
        if (nodes.containsKey(node1) && nodes.containsKey(node2)) {
            nodes.get(node1).add(new Pair<>(node2, weight));
            nodes.get(node2).add(new Pair<>(node1, weight));
        }
    }
}

class PathFinder {
    private Graph graph;

    public PathFinder(Graph graph) {
        this.graph = graph;
    }

    public List<String> findShortestPath(String start, String end) {
        Queue<Pair<String, Integer>> queue = new LinkedList<>();
        queue.add(new Pair<>(start, 0));
        Set<String> visited = new HashSet<>();
        Map<String, List<String>> paths = new HashMap<>();
        paths.put(start, new ArrayList<>());

        while (!queue.isEmpty()) {
            Pair<String, Integer> current = queue.poll();
            String node = current.getKey();
            int distance = current.getValue();

            if (node.equals(end)) {
                List<String> path = new ArrayList<>(paths.get(node));
                path.add(node);
                return path;
            }

            if (!visited.contains(node)) {
                visited.add(node);
                for (Pair<String, Integer> neighbor : graph.nodes.get(node)) {
                    String neighborNode = neighbor.getKey();
                    if (!visited.contains(neighborNode)) {
                        queue.add(new Pair<>(neighborNode, distance + neighbor.getValue()));
                        List<String> newPath = new ArrayList<>(paths.get(node));
                        newPath.add(node);
                        paths.put(neighborNode, newPath);
                    }
                }
            }
        }
        return new ArrayList<>();
    }
}

class sample_2700 {
    public static void main(String[] args) {
        Graph g = new Graph();
        g.addNode("A");
        g.addNode("B");
        g.addNode("C");
        g.addNode("D");
        g.addNode("E");
        g.addNode("F");
        g.addNode("G");
        g.addEdge("A", "B", 1);
        g.addEdge("A", "C", 4);
        g.addEdge("B", "C", 2);
        g.addEdge("B", "D", 5);
        g.addEdge("C", "D", 1);
        g.addEdge("C", "E", 3);
        g.addEdge("D", "E", 1);
        g.addEdge("D", "F", 8);
        g.addEdge("E", "F", 2);
        g.addEdge("E", "G", 2);
        g.addEdge("F", "G", 7);
        PathFinder pf = new PathFinder(g);
        List<String> path = pf.findShortestPath("A", "G");
        System.out.println(path);
    }
}

class Pair<K, V> {
    private K key;
    private V value;

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