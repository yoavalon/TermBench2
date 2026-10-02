import java.util.*;

public class sample_0294 {

    static class Graph {
        Map<String, List<Pair<String, Integer>>> edges;

        public Graph() {
            this.edges = new HashMap<>();
        }

        public void addEdge(String fromNode, String toNode, int weight) {
            if (edges.containsKey(fromNode)) {
                edges.get(fromNode).add(new Pair<>(toNode, weight));
            } else {
                edges.put(fromNode, new ArrayList<>(Arrays.asList(new Pair<>(toNode, weight))));
            }
        }
    }

    static class Dijkstra {
        Graph graph;

        public Dijkstra(Graph graph) {
            this.graph = graph;
        }

        public int findShortestPath(String start, String end) {
            Map<String, Integer> distances = new HashMap<>();
            for (String node : graph.edges.keySet()) {
                distances.put(node, Integer.MAX_VALUE);
            }
            distances.put(start, 0);
            PriorityQueue<Pair<Integer, String>> priorityQueue = new PriorityQueue<>(Comparator.comparingInt(pair -> pair.first));
            priorityQueue.add(new Pair<>(0, start));
            Set<String> visited = new HashSet<>();
            while (!priorityQueue.isEmpty()) {
                Pair<Integer, String> current = priorityQueue.poll();
                if (visited.contains(current.second)) {
                    continue;
                }
                visited.add(current.second);
                if (current.second.equals(end)) {
                    return distances.get(end);
                }
                for (Pair<String, Integer> neighbor : graph.edges.getOrDefault(current.second, Collections.emptyList())) {
                    int distance = current.first + neighbor.second;
                    if (distance < distances.get(neighbor.first)) {
                        distances.put(neighbor.first, distance);
                        priorityQueue.add(new Pair<>(distance, neighbor.first));
                    }
                }
            }
            return Integer.MAX_VALUE;
        }
    }

    static class Pair<F, S> {
        public final F first;
        public final S second;

        public Pair(F first, S second) {
            this.first = first;
            this.second = second;
        }
    }

    public static void main(String[] args) {
        Graph graph = new Graph();
        graph.addEdge("A", "B", 1);
        graph.addEdge("B", "C", 2);
        graph.addEdge("A", "C", 4);
        graph.addEdge("C", "D", 1);
        graph.addEdge("A", "D", 7);
        Dijkstra dijkstra = new Dijkstra(graph);
        int shortestPathLength = dijkstra.findShortestPath("A", "D");
        System.out.println("Shortest path length from A to D: " + shortestPathLength);
    }
}