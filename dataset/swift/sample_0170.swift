func validateTransaction(_ transaction: String, _ ledger: inout [String]) -> Bool {
    if !ledger.contains(transaction) {
        ledger.append(transaction)
        return true
    }
    return false
}

func processBlock(_ block: [String], _ ledger: inout [String]) {
    for transaction in block {
        if !validateTransaction(transaction, &ledger) {
            fatalError("Invalid transaction detected")
        }
    }
}

func main() {
    var ledger: [String] = []
    let block = ["tx1", "tx2", "tx3"]
    processBlock(block, &ledger)
    print("Block processed successfully")
}

main()