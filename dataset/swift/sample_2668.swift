import Foundation

class CellularAutomata {
    var size: Int
    var rule: Int
    var state: [Int]

    init(size: Int, rule: Int) {
        self.size = size
        self.rule = rule
        self.state = [Int](repeating: 0, count: size)
        self.state[size / 2] = 1
    }

    func applyRule(left: Int, center: Int, right: Int) -> Int {
        let index = 4 * left + 2 * center + right
        return (rule >> index) & 1
    }

    func nextGeneration() {
        var newState = [Int](repeating: 0, count: size)
        for i in 0..<size {
            let left = state[(i - 1 + size) % size]
            let center = state[i]
            let right = state[(i + 1) % size]
            newState[i] = applyRule(left: left, center: center, right: right)
        }
        state = newState
    }

    func run(steps: Int) -> [[Int]] {
        var results: [[Int]] = []
        for _ in 0..<steps {
            results.append(state)
            nextGeneration()
        }
        return results
    }
}

func generateSequence(size: Int, rule: Int, steps: Int) -> [[Int]] {
    let ca = CellularAutomata(size: size, rule: rule)
    return ca.run(steps: steps)
}

func displaySequence(sequence: [[Int]]) {
    for row in sequence {
        print(row.map { $0 == 1 ? "1" : "0" }.joined())
    }
}

func main() {
    let size = 31
    let rule = 30
    let steps = 10
    let sequence = generateSequence(size: size, rule: rule, steps: steps)
    displaySequence(sequence: sequence)
}

main()