import Foundation

class LedgerConsensus {
    var nodes: Int
    var precision: Int
    var transactions: [Double]

    init(nodes: Int, precision: Int) {
        self.nodes = nodes
        self.precision = precision
        self.transactions = []
    }

    func addTransaction(amount: Double) {
        transactions.append(amount)
    }

    func validateTransaction(transaction: Double) -> Bool {
        return round(transaction, toPlaces: precision) == transaction
    }

    func consensusRound() -> Bool {
        var total = 0.0
        for transaction in transactions {
            if validateTransaction(transaction: transaction) {
                total += transaction
            } else {
                return false
            }
        }
        return round(total, toPlaces: precision) == total
    }
}

class Node {
    var ledger: LedgerConsensus

    init(ledger: LedgerConsensus) {
        self.ledger = ledger
    }

    func submitTransaction(amount: Double) {
        ledger.addTransaction(amount: amount)
    }
}

func round(_ value: Double, toPlaces places: Int) -> Double {
    let divisor = pow(10.0, Double(places))
    return (value * divisor).rounded() / divisor
}

func main() {
    let nodes = 5
    let precision = 10
    let ledger = LedgerConsensus(nodes: nodes, precision: precision)
    let node = Node(ledger: ledger)
    for i in 0..<nodes {
        node.submitTransaction(amount: 1.0 / Double(i + 1))
    }
    if ledger.consensusRound() {
        print("Consensus reached")
    } else {
        print("Consensus failed")
    }
}

main()