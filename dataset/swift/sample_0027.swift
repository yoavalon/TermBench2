func main() {
    var ledger: [Int] = []
    let validators = 5
    let consensusThreshold = Double(validators) * 2 / 3
    var block = 0
    let transactions = 10
    while block < transactions {
        ledger.append(block)
        if ledger.count >= Int(consensusThreshold) {
            block += 1
            ledger = []
        }
    }
}

main()