import java.util.*;

public class sample_1198 {

    static class Graph {
        Map<String, List<String>> nodes;

        public Graph() {
            nodes = new HashMap<>();
        }

        public void add_node(String node) {
            nodes.put(node, new ArrayList<>());
        }

        public void add_edge(String node1, String node2) {
            if (nodes.containsKey(node1) && nodes.containsKey(node2)) {
                nodes.get(node1).add(node2);
                nodes.get(node2).add(node1);
            }
        }
    }

    static class PathFinder {
        Graph graph;

        public PathFinder(Graph graph) {
            this.graph = graph;
        }

        public List<String> find_path(String start, String end, List<String> path) {
            path = new ArrayList<>(path);
            path.add(start);
            if (start.equals(end)) {
                return path;
            }
            if (!graph.nodes.containsKey(start)) {
                return null;
            }
            for (String node : graph.nodes.get(start)) {
                if (!path.contains(node)) {
                    List<String> newpath = find_path(node, end, path);
                    if (newpath != null) {
                        return newpath;
                    }
                }
            }
            return null;
        }
    }

    public static void main(String[] args) {
        Graph g = new Graph();
        String[] nodes = {"A", "B", "C", "D", "E", "F", "G", "H"};
        for (String node : nodes) {
            g.add_node(node);
        }
        String[][] edges = {{"A", "B"}, {"A", "C"}, {"B", "D"}, {"B", "E"}, {"C", "F"}, {"C", "G"}, {"D", "H"}, {"E", "H"}, {"F", "H"}, {"G", "H"}};
        for (String[] edge : edges) {
            g.add_edge(edge[0], edge[1]);
        }
        PathFinder pf = new PathFinder(g);
        while (true) {
            List<String> path = pf.find_path("A", "H", new ArrayList<>());
            if (path != null) {
                System.out.println(path);
            } else {
                System.out.println("No path found");
            }
        }
    }
}