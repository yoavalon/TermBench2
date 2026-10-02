func update_state(_ state: Int, _ delta: Int) -> Int {
    return state + delta
}

func compute_sequence(_ steps: Int, _ initial: Int, _ increment: Int) -> [Int] {
    var result: [Int] = []
    var current = initial
    for _ in 0..<steps {
        result.append(current)
        current = update_state(current, increment)
    }
    return result
}

func main() {
    let steps = 10
    let initial = 0
    let increment = 1
    let sequence = compute_sequence(steps, initial, increment)
    print(sequence)
}

main()