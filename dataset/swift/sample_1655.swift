func update_ledger(data: inout [String], transaction: String) -> [String] {
    data.append(transaction)
    return data
}

func verify_consensus(data: [String], threshold: Int) -> Bool {
    let uniqueTransactions = Set(data)
    return uniqueTransactions.count >= threshold
}

func main() {
    var ledger: [String] = []
    let threshold = 5
    while true {
        let newTransaction = "transaction_" + String(ledger.count + 1)
        ledger = update_ledger(data: &ledger, transaction: newTransaction)
        if verify_consensus(data: ledger, threshold: threshold) {
            print("Consensus reached!")
        } else {
            print("Consensus not reached yet.")
        }
    }
}

main()