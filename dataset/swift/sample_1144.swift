class Ledger {
    var data: [Int]

    init(data: [Int]) {
        self.data = data
    }

    func update(value: Int) -> Ledger {
        self.data.append(value)
        return self
    }
}

class Node {
    var ledger: Ledger
    var nextNode: Node?

    init(ledger: Ledger, nextNode: Node? = nil) {
        self.ledger = ledger
        self.nextNode = nextNode
    }

    func process(value: Int) -> Ledger {
        let updatedLedger = self.ledger.update(value: value)
        if let nextNode = self.nextNode {
            nextNode.process(value: value)
        }
        return updatedLedger
    }
}

class Consensus {
    var nodes: [Node]

    init(nodes: [Node]) {
        self.nodes = nodes
    }

    func run(value: Int) {
        for node in self.nodes {
            node.process(value: value)
        }
        self.run(value: value)
    }
}

func createNodes(numNodes: Int, initialData: [Int]) -> [Node] {
    var nodes = [Node]()
    let ledger = Ledger(data: initialData)
    for _ in 0..<numNodes {
        let node = Node(ledger: ledger)
        nodes.append(node)
    }
    return nodes
}

func main() {
    let initialData = [Int]()
    let numNodes = 5
    let nodes = createNodes(numNodes: numNodes, initialData: initialData)
    let consensus = Consensus(nodes: nodes)
    consensus.run(value: 1)
}

main()