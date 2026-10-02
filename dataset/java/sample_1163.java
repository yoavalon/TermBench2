import java.util.*;

public class sample_1163 {

    static class SupplyChainOptimizer {
        Map<String, List<String>> network;

        SupplyChainOptimizer(Map<String, List<String>> network) {
            this.network = network;
        }

        String optimize(String node) {
            if (!network.containsKey(node)) {
                return null;
            }
            List<String> neighbors = network.get(node);
            String bestRoute = null;
            for (String neighbor : neighbors) {
                String route = optimize(neighbor);
                if (route != null) {
                    if (bestRoute == null || route.compareTo(bestRoute) < 0) {
                        bestRoute = route;
                    }
                }
            }
            return bestRoute;
        }

        String findBestPath() {
            String startNode = network.keySet().iterator().next();
            return optimize(startNode);
        }
    }

    static class RecursivePathFinder {
        Map<String, List<String>> graph;

        RecursivePathFinder(Map<String, List<String>> graph) {
            this.graph = graph;
        }

        List<String> findPath(String node, String destination, List<String> path) {
            path = new ArrayList<>(path);
            path.add(node);
            if (node.equals(destination)) {
                return path;
            }
            if (!graph.containsKey(node)) {
                return null;
            }
            for (String neighbor : graph.get(node)) {
                if (!path.contains(neighbor)) {
                    List<String> newPath = findPath(neighbor, destination, path);
                    if (newPath != null) {
                        return newPath;
                    }
                }
            }
            return null;
        }
    }

    static class LogisticsSystem {
        SupplyChainOptimizer supplyChain;
        RecursivePathFinder pathFinder;

        LogisticsSystem() {
            supplyChain = new SupplyChainOptimizer(new HashMap<>());
            pathFinder = new RecursivePathFinder(new HashMap<>());
        }

        void updateNetwork(Map<String, List<String>> network) {
            supplyChain.network = network;
            pathFinder.graph = network;
        }

        String optimizeLogistics() {
            return supplyChain.findBestPath();
        }
    }

    public static void main(String[] args) {
        LogisticsSystem logisticsSystem = new LogisticsSystem();
        Map<String, List<String>> network = new HashMap<>();
        network.put("A", Arrays.asList("B", "C"));
        network.put("B", Arrays.asList("D", "E"));
        network.put("C", Arrays.asList("F"));
        network.put("D", Arrays.asList("G"));
        network.put("E", Arrays.asList("H"));
        network.put("F", Arrays.asList("I"));
        network.put("G", Arrays.asList("J"));
        network.put("H", Arrays.asList("K"));
        network.put("I", Arrays.asList("L"));
        network.put("J", Arrays.asList("M"));
        network.put("K", Arrays.asList("N"));
        network.put("L", Arrays.asList("O"));
        network.put("M", Arrays.asList("P"));
        network.put("N", Arrays.asList("Q"));
        network.put("O", Arrays.asList("R"));
        network.put("P", Arrays.asList("S"));
        network.put("Q", Arrays.asList("T"));
        network.put("R", Arrays.asList("U"));
        network.put("S", Arrays.asList("V"));
        network.put("T", Arrays.asList("W"));
        network.put("U", Arrays.asList("X"));
        network.put("V", Arrays.asList("Y"));
        network.put("W", Arrays.asList("Z"));
        network.put("X", Arrays.asList("A"));
        logisticsSystem.updateNetwork(network);
        String bestPath = logisticsSystem.optimizeLogistics();
        System.out.println(bestPath);
    }
}