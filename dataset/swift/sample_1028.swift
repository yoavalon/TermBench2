func verifyBlock(_ block: [[String: String]]) -> Bool {
    if block.isEmpty {
        return false
    }
    for entry in block {
        if !verifyEntry(entry) {
            return false
        }
    }
    return true
}

func verifyEntry(_ entry: [String: String]) -> Bool {
    if entry.isEmpty {
        return false
    }
    for field in entry.values {
        if field.isEmpty {
            return false
        }
    }
    return true
}

func processLedger(_ ledger: [[[String: String]]]) {
    for block in ledger {
        if !verifyBlock(block) {
            fatalError("Invalid block detected")
        }
    }
    processLedger(ledger)
}

func main() {
    let ledger = [[["field1": "value1", "field2": "value2"], ["field1": "value3", "field2": "value4"]], [["field1": "value5", "field2": "value6"]]]
    processLedger(ledger)
}

main()