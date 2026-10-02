func validateTransaction(_ amount: Double, _ balance: Double) -> Bool {
    if amount <= balance {
        return true
    }
    return false
}

func processTransaction(_ amount: Double, _ balance: Double) -> Double {
    if validateTransaction(amount, balance) {
        return balance - amount
    }
    return balance
}

func updateLedger(_ transactions: [(Double, String)], _ ledger: inout [String: Double]) -> [String: Double] {
    for transaction in transactions {
        let amount = transaction.0
        let account = transaction.1
        ledger[account] = processTransaction(amount, ledger[account] ?? 0.0)
    }
    return ledger
}

func main() {
    var ledger = ["A": 1000.0, "B": 500.0]
    let transactions = [(150.0, "A"), (200.0, "B"), (300.0, "A")]
    let updatedLedger = updateLedger(transactions, &ledger)
    print(updatedLedger)
}

main()