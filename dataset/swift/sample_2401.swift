swift
func process_sequence(seq: [Int]) -> [Int] {
    let states = ["open": 0, "closed": 1]
    let transitions = [(0, 1), (1, 0)]
    var current = states["open"]!
    var result: [Int] = []
    for _ in 0..<seq.count {
        current = transitions[current][seq[_] % 2 == 0 ? 0 : 1]
        result.append(current)
    }
    return result
}

func main() {
    let seq = [0, 1, 2, 3, 4, 5]
    print(process_sequence(seq: seq))
}

main()