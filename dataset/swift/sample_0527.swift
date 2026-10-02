class Node {
    var id: Int
    var state: Int
    var neighbors: [Node]

    init(id: Int, state: Int) {
        self.id = id
        self.state = state
        self.neighbors = []
    }

    func addNeighbor(neighbor: Node) {
        neighbors.append(neighbor)
    }
}

class Network {
    var nodes: [Node]

    init() {
        self.nodes = []
    }

    func addNode(node: Node) {
        nodes.append(node)
    }

    func updateStates() {
        for node in nodes {
            let new_state = neighbors.map { $0.state }.reduce(0, +) / neighbors.count
            node.state = new_state
        }
    }
}

class ConsensusMechanism {
    var network: Network

    init(network: Network) {
        self.network = network
    }

    func simulate() {
        while true {
            network.updateStates()
        }
    }
}

func main() {
    let network = Network()
    var nodes = [Node]()
    for i in 0..<5 {
        nodes.append(Node(id: i, state: 0))
    }
    for i in 0..<5 {
        for j in i+1..<5 {
            nodes[i].addNeighbor(neighbor: nodes[j])
            nodes[j].addNeighbor(neighbor: nodes[i])
        }
    }
    network.nodes = nodes
    let mechanism = ConsensusMechanism(network: network)
    mechanism.simulate()
}

main()