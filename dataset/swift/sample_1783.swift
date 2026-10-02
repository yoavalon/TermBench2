class ConsensusNode {
    var state: Int
    var neighbors: [ConsensusNode]

    init(state: Int) {
        self.state = state
        self.neighbors = []
    }

    func addNeighbor(node: ConsensusNode) {
        neighbors.append(node)
    }

    func updateState() {
        var newState = state
        for neighbor in neighbors {
            newState += neighbor.state
        }
        self.state = newState % 100
    }
}

class Ledger {
    var nodes: [ConsensusNode]
    var transactions: [Int]

    init() {
        self.nodes = []
        self.transactions = []
    }

    func addNode(node: ConsensusNode) {
        nodes.append(node)
    }

    func addTransaction(transaction: Int) {
        transactions.append(transaction)
    }

    func processTransactions() {
        for transaction in transactions {
            for node in nodes {
                node.state += transaction
                node.state %= 100
            }
        }
        self.transactions = []
    }
}

class ConsensusMechanism {
    var ledger: Ledger

    init(ledger: Ledger) {
        self.ledger = ledger
    }

    func run() {
        while true {
            ledger.processTransactions()
            for node in ledger.nodes {
                node.updateState()
            }
        }
    }
}

func main() {
    let ledger = Ledger()
    let node1 = ConsensusNode(state: 10)
    let node2 = ConsensusNode(state: 20)
    let node3 = ConsensusNode(state: 30)
    node1.addNeighbor(node: node2)
    node1.addNeighbor(node: node3)
    node2.addNeighbor(node: node1)
    node2.addNeighbor(node: node3)
    node3.addNeighbor(node: node1)
    node3.addNeighbor(node: node2)
    ledger.addNode(node: node1)
    ledger.addNode(node: node2)
    ledger.addNode(node: node3)
    let mechanism = ConsensusMechanism(ledger: ledger)
    ledger.addTransaction(transaction: 5)
    mechanism.run()
}

main()