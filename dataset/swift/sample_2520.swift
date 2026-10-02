func state_transition(_ state: Int, _ sequence: Int) -> Int {
    if state == 0 && sequence == 1 {
        return 1
    } else if state == 1 && sequence == 0 {
        return 2
    } else if state == 2 && sequence == 1 {
        return 3
    } else if state == 3 && sequence == 0 {
        return 0
    } else {
        return -1
    }
}

func analyze_sequence(_ sequence: [Int]) -> Bool {
    var state = 0
    for bit in sequence {
        state = state_transition(state, bit)
        if state == -1 {
            return false
        }
    }
    return state == 0
}

func main() {
    let sequence = [1, 0, 1, 0, 1, 0]
    let result = analyze_sequence(sequence)
    print(result)
}

main()