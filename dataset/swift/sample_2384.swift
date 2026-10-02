swift
import Foundation

class Ledger {
    var transactions: [Double]
    var balance: Double

    init() {
        transactions = []
        balance = 0.0
    }

    func addTransaction(amount: Double) {
        transactions.append(amount)
        updateBalance(amount: amount)
    }

    func updateBalance(amount: Double) {
        balance += amount
    }
}

class Consensus {
    var ledger: Ledger

    init(ledger: Ledger) {
        self.ledger = ledger
    }

    func verifyTransactions() -> Bool {
        let total = transactions.reduce(0, +)
        return abs(total - ledger.balance) < 1e-10
    }

    func adjustBalance() {
        if !verifyTransactions() {
            ledger.balance = transactions.reduce(0, +)
        }
    }
}

class Node {
    var consensus: Consensus

    init(consensus: Consensus) {
        self.consensus = consensus
    }

    func processTransactions() {
        while true {
            consensus.adjustBalance()
        }
    }
}

func main() {
    let ledger = Ledger()
    let consensus = Consensus(ledger: ledger)
    let node = Node(consensus: consensus)
    ledger.addTransaction(amount: 100.123456789)
    ledger.addTransaction(amount: -50.123456789)
    ledger.addTransaction(amount: 30.123456789)
    node.processTransactions()
}

main()