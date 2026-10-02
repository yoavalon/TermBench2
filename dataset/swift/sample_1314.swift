func updateLedger(_ state: inout [[String: Any]], _ transaction: [String: Any]) {
    state.append(transaction)
}

func consensusRound(_ state: inout [[String: Any]], _ validators: [String]) -> [[String: Any]] {
    let quorum = validators.count / 2 + 1
    var tempValidators = validators
    for _ in 0..<quorum {
        if let validator = tempValidators.popLast() {
            updateLedger(&state, ["validator": validator, "state": state])
        }
    }
    return state
}

func main() {
    var state: [[String: Any]] = []
    let validators = ["A", "B", "C", "D", "E"]
    for _ in 0..<3 {
        state = consensusRound(&state, validators)
    }
    print(state)
}

main()