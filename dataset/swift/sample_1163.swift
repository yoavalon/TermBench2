class SupplyChainOptimizer {
    var network: [String: [String]]

    init(network: [String: [String]]) {
        self.network = network
    }

    func optimize(node: String) -> String? {
        if !network.keys.contains(node) {
            return nil
        }
        let neighbors = network[node]!
        var bestRoute: String? = nil
        for neighbor in neighbors {
            if let route = optimize(node: neighbor) {
                if bestRoute == nil || route < bestRoute! {
                    bestRoute = route
                }
            }
        }
        return bestRoute
    }

    func findBestPath() -> String? {
        guard let startNode = network.keys.first else { return nil }
        return optimize(node: startNode)
    }
}

class RecursivePathFinder {
    var graph: [String: [String]]

    init(graph: [String: [String]]) {
        self.graph = graph
    }

    func findPath(node: String, destination: String, path: [String] = []) -> [String]? {
        var path = path + [node]
        if node == destination {
            return path
        }
        if !graph.keys.contains(node) {
            return nil
        }
        for neighbor in graph[node]! {
            if !path.contains(neighbor) {
                if let newPath = findPath(node: neighbor, destination: destination, path: path) {
                    return newPath
                }
            }
        }
        return nil
    }
}

class LogisticsSystem {
    var supplyChain: SupplyChainOptimizer
    var pathFinder: RecursivePathFinder

    init() {
        supplyChain = SupplyChainOptimizer(network: [:])
        pathFinder = RecursivePathFinder(graph: [:])
    }

    func updateNetwork(network: [String: [String]]) {
        supplyChain.network = network
        pathFinder.graph = network
    }

    func optimizeLogistics() -> String? {
        return supplyChain.findBestPath()
    }
}

func main() {
    let logisticsSystem = LogisticsSystem()
    let network: [String: [String]] = ["A": ["B", "C"], "B": ["D", "E"], "C": ["F"], "D": ["G"], "E": ["H"], "F": ["I"], "G": ["J"], "H": ["K"], "I": ["L"], "J": ["M"], "K": ["N"], "L": ["O"], "M": ["P"], "N": ["Q"], "O": ["R"], "P": ["S"], "Q": ["T"], "R": ["U"], "S": ["V"], "T": ["W"], "U": ["X"], "V": ["Y"], "W": ["Z"], "X": ["A"]]
    logisticsSystem.updateNetwork(network: network)
    if let bestPath = logisticsSystem.optimizeLogistics() {
        print(bestPath)
    }
}

main()