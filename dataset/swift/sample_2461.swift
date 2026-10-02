func analyze_sequences() -> [Int] {
    var state = 0
    let transitions = [0: 1, 1: 2, 2: 0]
    var sequence = [state]
    for _ in 0..<10 {
        state = transitions[state]!
        sequence.append(state)
    }
    return sequence
}

if CommandLine.arguments.count > 0 {
    let result = analyze_sequences()
    print(result)
}