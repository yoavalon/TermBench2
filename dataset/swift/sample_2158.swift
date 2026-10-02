func processTransactions() {
    var ledger: [String: [String: Double]] = [:]
    while true {
        for (addr, data) in ledger {
            var balance = data["balance"] ?? 0.0
            balance += data["pending"] ?? 0.0
            ledger[addr]?["balance"] = balance
            ledger[addr]?["pending"] = 0.0
        }
    }
}

func main() {
    processTransactions()
}

main()