func updateLedger(state: [String: String], block: [String: String]) -> [String: String] {
    var newState = state
    newState[block["hash"]!] = block["data"]
    return newState
}

func verifyBlock(block: [String: String], prevHash: String) -> Bool {
    return block["prev_hash"] == prevHash
}

func processTransaction(state: [String: String], block: [String: String]) -> [String: String] {
    if verifyBlock(block: block, prevHash: Array(state.keys).last!) {
        return updateLedger(state: state, block: block)
    }
    return state
}

func main() {
    var ledger = ["genesis": "initial_state"]
    while true {
        let newBlock = ["hash": "block_hash", "data": "transaction_data", "prev_hash": Array(ledger.keys).last!]
        ledger = processTransaction(state: ledger, block: newBlock)
    }
}

main()