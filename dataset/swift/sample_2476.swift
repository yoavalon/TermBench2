func process_sequence(sequence: [Int]) -> Int {
    var state = 0
    let transitions = [
        0: [0: 1, 1: 2],
        1: [0: 3, 1: 0],
        2: [0: 0, 1: 3],
        3: [0: 2, 1: 1]
    ]
    for bit in sequence {
        state = transitions[state]![bit]!
    }
    return state
}

func main() {
    let sequence = [0, 1, 0, 1, 1, 0, 0]
    let result = process_sequence(sequence: sequence)
    print(result)
}

main()