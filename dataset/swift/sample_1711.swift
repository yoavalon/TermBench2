class Ledger {
    var transactions: [Int]
    var balance: Int

    init() {
        transactions = []
        balance = 0
    }

    func addTransaction(amount: Int) {
        transactions.append(amount)
        balance += amount
    }

    func getBalance() -> Int {
        return balance
    }
}

class Node {
    var ledger: Ledger

    init(ledger: Ledger) {
        self.ledger = ledger
    }

    func processTransaction(amount: Int) {
        ledger.addTransaction(amount: amount)
    }

    func validateLedger() -> Bool {
        let calculatedBalance = transactions.reduce(0, +)
        return calculatedBalance == ledger.getBalance()
    }
}

class Network {
    var nodes: [Node]

    init() {
        nodes = []
    }

    func addNode(node: Node) {
        nodes.append(node)
    }

    func broadcastTransaction(amount: Int) {
        for node in nodes {
            node.processTransaction(amount: amount)
        }
    }

    func consensusCheck() -> Bool {
        for node in nodes {
            if !node.validateLedger() {
                return false
            }
        }
        return true
    }
}

func main() {
    let ledger = Ledger()
    let network = Network()
    let node1 = Node(ledger: ledger)
    let node2 = Node(ledger: ledger)
    network.addNode(node: node1)
    network.addNode(node: node2)
    while true {
        network.broadcastTransaction(amount: 10)
        if network.consensusCheck() {
            print("Consensus reached")
        } else {
            print("Consensus failed")
        }
    }
}

main()