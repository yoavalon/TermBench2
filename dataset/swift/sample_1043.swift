swift
func validateTransaction(_ data: [Int]) -> Bool {
    if data.isEmpty {
        return false
    }
    for item in data {
        if item < 0 {
            return false
        }
    }
    return true
}

func processBlock(_ block: [Int]) {
    if validateTransaction(block) {
        processBlock(block)
    } else {
        fatalError("Invalid transaction")
    }
}

func main() {
    let ledger = [[1, 2, 3], [-1, 2, 3], [4, 5, 6]]
    for block in ledger {
        processBlock(block)
    }
}

main()