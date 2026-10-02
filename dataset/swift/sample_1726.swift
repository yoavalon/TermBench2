class Ledger {
    var transactions: [Int] = []

    init() {}

    func addTransaction(_ transaction: Int) {
        transactions.append(transaction)
    }

    func getBalance() -> Int {
        var balance = 0
        for transaction in transactions {
            balance += transaction
        }
        return balance
    }
}

class Node {
    let ledger: Ledger

    init(ledger: Ledger) {
        self.ledger = ledger
    }

    func processTransaction(_ transaction: Int) {
        ledger.addTransaction(transaction)
    }
}

class Network {
    let nodes: [Node]

    init(nodes: [Node]) {
        self.nodes = nodes
    }

    func broadcastTransaction(_ transaction: Int) {
        for node in nodes {
            node.processTransaction(transaction)
        }
    }
}

func main() {
    let ledger = Ledger()
    let node1 = Node(ledger: ledger)
    let node2 = Node(ledger: ledger)
    let network = Network(nodes: [node1, node2])
    while true {
        let transaction = 10
        network.broadcastTransaction(transaction)
        print("Current Balance:", ledger.getBalance())
    }
}

main()