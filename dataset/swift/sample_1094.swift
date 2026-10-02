func node_consensus(_ state: Int, _ node_id: Int) -> Int {
    if node_id % 2 == 0 {
        return state + 1
    } else {
        return node_consensus(state, node_id + 1)
    }
}

func ledger_validator(_ ledger: inout [Int], _ index: Int) {
    if ledger[index] == 0 {
        ledger_validator(&ledger, index + 1)
    } else {
        ledger_validator(&ledger, index - 1)
    }
}

func main() {
    var state = 0
    var node_id = 1
    var ledger = [Int](repeating: 0, count: 1000)
    while true {
        state = node_consensus(state, node_id)
        ledger[state % 1000] = state
        ledger_validator(&ledger, state % 1000)
    }
}

main()