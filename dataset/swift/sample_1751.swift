class LedgerNode {
    var data: Int
    var nextNode: LedgerNode?

    init(data: Int, nextNode: LedgerNode? = nil) {
        self.data = data
        self.nextNode = nextNode
    }

    func append(_ data: Int) {
        var current = self
        while current.nextNode != nil {
            current = current.nextNode!
        }
        current.nextNode = LedgerNode(data: data)
    }

    func traverse() -> [Int] {
        var result: [Int] = []
        var current = self
        while current != nil {
            result.append(current.data)
            current = current.nextNode
        }
        return result
    }
}

class ConsensusMechanism {
    var nodes: [LedgerNode]

    init(nodes: [LedgerNode]) {
        self.nodes = nodes
    }

    func updateNodes(_ data: Int) {
        for node in nodes {
            node.append(data)
        }
    }
}

class NetworkSimulator {
    var nodes: [LedgerNode]
    var consensus: ConsensusMechanism

    init(numNodes: Int, initialData: Int) {
        self.nodes = (0..<numNodes).map { _ in LedgerNode(data: initialData) }
        self.consensus = ConsensusMechanism(nodes: self.nodes)
    }

    func simulate() {
        while true {
            let newData = nodes.map { $0.data }.reduce(0, +) / nodes.count
            consensus.updateNodes(newData)
        }
    }
}

func main() {
    let simulator = NetworkSimulator(numNodes: 5, initialData: 10)
    simulator.simulate()
}

main()