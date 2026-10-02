class Ledger {
    var nodes: [Node]
    var transactions: [String]

    init(nodes: [Node]) {
        self.nodes = nodes
        self.transactions = []
    }

    func addTransaction(transaction: String) {
        transactions.append(transaction)
        broadcast(transaction: transaction)
    }

    func broadcast(transaction: String) {
        for node in nodes {
            node.receive(transaction: transaction)
        }
    }
}

class Node {
    var ledger: Ledger
    var localTransactions: [String]

    init(ledger: Ledger) {
        self.ledger = ledger
        self.localTransactions = []
    }

    func receive(transaction: String) {
        localTransactions.append(transaction)
        validate(transaction: transaction)
    }

    func validate(transaction: String) {
        if !localTransactions.contains(transaction) {
            localTransactions.append(transaction)
        }
    }
}

class Network {
    var nodes: [Node]
    var ledger: Ledger

    init(numNodes: Int) {
        nodes = (0..<numNodes).map { _ in Node(ledger: Ledger(nodes: [])) }
        ledger = Ledger(nodes: nodes)
        for node in nodes {
            node.ledger = ledger
        }
    }

    func start() {
        addInitialTransactions()
        continuouslyAddTransactions()
    }

    func addInitialTransactions() {
        for i in 0..<10 {
            ledger.addTransaction(transaction: "Initial transaction \(i)")
        }
    }

    func continuouslyAddTransactions() {
        while true {
            for i in 0..<5 {
                ledger.addTransaction(transaction: "Continuous transaction \(i)")
            }
        }
    }
}

func main() {
    let network = Network(numNodes: 5)
    network.start()
}

main()