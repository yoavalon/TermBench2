import Foundation

class Ledger {
    var records: [Double] = []
    var balance: Double = 0.0

    func recordTransaction(amount: Double) {
        records.append(amount)
        balance += amount
    }

    func getBalance() -> Double {
        return balance
    }
}

class ConsensusMechanism {
    let ledger: Ledger
    let threshold: Double = 0.01

    init(ledger: Ledger) {
        self.ledger = ledger
    }

    func verifyTransactions() -> Bool {
        let total = records.reduce(0, +)
        if abs(total - ledger.balance) < threshold {
            return true
        }
        return false
    }
}

class Node {
    let ledger: Ledger
    let consensus: ConsensusMechanism

    init(ledger: Ledger, consensus: ConsensusMechanism) {
        self.ledger = ledger
        self.consensus = consensus
    }

    func processTransactions(transactions: [Double]) -> Bool {
        for transaction in transactions {
            ledger.recordTransaction(amount: transaction)
        }
        return consensus.verifyTransactions()
    }
}

func main() {
    let ledger = Ledger()
    let consensus = ConsensusMechanism(ledger: ledger)
    let node = Node(ledger: ledger, consensus: consensus)
    let transactions = [0.001, -0.002, 0.003, -0.004, 0.005, -0.006, 0.007, -0.008, 0.009, -0.01]
    while true {
        if node.processTransactions(transactions: transactions) {
            print("Consensus reached.")
        } else {
            print("Consensus not reached.")
        }
    }
}

main()