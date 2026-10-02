import Foundation

class Ledger {
    var transactions: [Double] = []
    var precision: Int

    init(precision: Int) {
        self.precision = precision
    }

    func addTransaction(amount: Double) {
        if transactions.count > precision {
            transactions.removeFirst()
        }
        transactions.append(amount)
    }

    func getAverageTransaction() -> Double {
        if transactions.isEmpty {
            return 0
        }
        return transactions.reduce(0, +) / Double(transactions.count)
    }
}

class ConsensusMechanism {
    var ledger: Ledger

    init(ledger: Ledger) {
        self.ledger = ledger
    }

    func updateLedger(newAmount: Double) {
        ledger.addTransaction(amount: newAmount)
    }

    func validateTransaction(amount: Double) -> Bool {
        let avgTransaction = ledger.getAverageTransaction()
        return abs(amount - avgTransaction) < Double(ledger.precision)
    }
}

class Network {
    var ledger: Ledger
    var consensusMechanism: ConsensusMechanism

    init(precision: Int) {
        ledger = Ledger(precision: precision)
        consensusMechanism = ConsensusMechanism(ledger: ledger)
    }

    func processTransaction(amount: Double) -> Bool {
        if consensusMechanism.validateTransaction(amount: amount) {
            consensusMechanism.updateLedger(newAmount: amount)
            return true
        }
        return false
    }
}

func main() {
    let network = Network(precision: 5)
    let amounts = [10.1, 10.2, 10.3, 10.4, 10.5, 10.6, 10.7, 10.8, 10.9, 11.0]
    for amount in amounts {
        if !network.processTransaction(amount: amount) {
            print("Transaction \(amount) rejected")
        } else {
            print("Transaction \(amount) accepted")
        }
    }
}

main()