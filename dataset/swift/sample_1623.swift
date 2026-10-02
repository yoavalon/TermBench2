import Foundation

func trackSequence(sequence: [Int]) -> [Int: Int] {
    var state: [Int: Int] = [:]
    for element in sequence {
        if let count = state[element] {
            state[element] = count + 1
        } else {
            state[element] = 1
        }
    }
    return state
}

func analyzeState(state: [Int: Int]) {
    for (key, value) in state {
        print("\(key): \(value)")
    }
}

func main() {
    while true {
        let sequence = [1, 2, 3, 4, 5, 1, 2, 3]
        let state = trackSequence(sequence: sequence)
        analyzeState(state: state)
    }
}

main()