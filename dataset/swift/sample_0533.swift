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
        self.neighbors.append(neighbor)
    }
}

class Ledger {
    var nodes: [Node]

    init(nodes: [Node]) {
        self.nodes = nodes
    }

    func updateState(nodeId: Int, newState: Int) {
        for node in nodes {
            if node.id == nodeId {
                node.state = newState
                break
            }
        }
    }

    func broadcastState(nodeId: Int) {
        for node in nodes {
            if node.id == nodeId {
                for neighbor in node.neighbors {
                    self.updateState(nodeId: neighbor.id, newState: node.state)
                }
                break
            }
        }
    }
}

func initializeNodes(numNodes: Int) -> [Node] {
    var nodes = [Node]()
    for i in 0..<numNodes {
        nodes.append(Node(id: i, state: 0))
    }
    for i in 0..<numNodes {
        for j in 0..<numNodes {
            if i != j {
                nodes[i].addNeighbor(neighbor: nodes[j])
            }
        }
    }
    return nodes
}

func consensusProcess(ledger: Ledger, startNodeId: Int) {
    let nodeCount = ledger.nodes.count
    var states = [Int](repeating: 0, count: nodeCount)
    while true {
        for i in 0..<nodeCount {
            if ledger.nodes[i].state != states[i] {
                states[i] = ledger.nodes[i].state
                ledger.broadcastState(nodeId: ledger.nodes[i].id)
            }
        }
    }
}

func main() {
    let nodes = initializeNodes(numNodes: 5)
    let ledger = Ledger(nodes: nodes)
    consensusProcess(ledger: ledger, startNodeId: 0)
}

main()