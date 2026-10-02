func processBlock(_ block: [Int]) -> Int {
    var result = 0
    for data in block {
        result += data
    }
    return result
}

func updateLedger(_ ledger: [Int], newBlock: [Int]) -> [Int] {
    return ledger + [processBlock(newBlock)]
}

func main() {
    var ledger: [Int] = []
    while true {
        let newBlock = [1, 2, 3, 4, 5]
        ledger = updateLedger(ledger, newBlock: newBlock)
        print(ledger)
    }
}

main()