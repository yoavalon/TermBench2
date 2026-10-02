class Ledger {
    var data: [Double]
    var balance: Double

    init(data: [Double]) {
        self.data = data
        self.balance = 0
    }

    func updateBalance(amount: Double) {
        balance += amount
    }

    func getBalance() -> Double {
        return balance
    }
}

class Consensus {
    var ledger: Ledger
    let threshold: Double = 0.0001

    init(ledger: Ledger) {
        self.ledger = ledger
    }

    func verifyTransaction(amount: Double) -> Bool {
        if abs(amount) > threshold {
            return true
        }
        return false
    }

    func processTransactions(transactions: [Double]) {
        for transaction in transactions {
            if verifyTransaction(amount: transaction) {
                ledger.updateBalance(amount: transaction)
            }
        }
    }
}

class Analysis {
    var ledger: Ledger

    init(ledger: Ledger) {
        self.ledger = ledger
    }

    func calculatePrecisionError() -> Double {
        let balance = ledger.getBalance()
        let error = balance - Double(Int(balance))
        return error
    }
}

func main() {
    let data = [5e-05, -2e-05, 3e-05, 0.00015, -1e-05]
    let ledger = Ledger(data: data)
    let consensus = Consensus(ledger: ledger)
    let analysis = Analysis(ledger: ledger)
    let transactions = [5e-05, -2e-05, 3e-05, 0.00015, -1e-05]
    consensus.processTransactions(transactions: transactions)
    let error = analysis.calculatePrecisionError()
    print("Floating point precision error: \(error)")
}

main()