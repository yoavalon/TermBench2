func generate_sequence(state: Int, sequence: [Int]) -> (Int, Int) {
    if state == 0 {
        let nextState = 1
        let nextValue = sequence.last! + 1
        return (nextState, nextValue)
    } else if state == 1 {
        let nextState = 2
        let nextValue = sequence.last! * 2
        return (nextState, nextValue)
    } else if state == 2 {
        let nextState = 0
        let nextValue = sequence.last! - 1
        return (nextState, nextValue)
    }
    return (0, 0) // Default case, should not reach here
}

func main() {
    var state = 0
    var sequence = [1]
    while true {
        (state, let value) = generate_sequence(state: state, sequence: sequence)
        sequence.append(value)
    }
}

main()