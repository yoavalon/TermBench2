import Foundation

class Automaton {
    var size: Int
    var state: [[Int]]

    init(size: Int, initialState: [[Int]]) {
        self.size = size
        self.state = initialState
    }

    func update() {
        var newState = Array(repeating: Array(repeating: 0, count: size), count: size)
        for i in 0..<size {
            for j in 0..<size {
                let neighbors = countNeighbors(x: i, y: j)
                if state[i][j] == 1 {
                    newState[i][j] = (2...3).contains(neighbors) ? 1 : 0
                } else {
                    newState[i][j] = neighbors == 3 ? 1 : 0
                }
            }
        }
        state = newState
    }

    func countNeighbors(x: Int, y: Int) -> Int {
        var count = 0
        for i in (x - 1)...(x + 1) {
            for j in (y - 1)...(y + 1) {
                if (0...size-1).contains(i) && (0...size-1).contains(j) && (i != x || j != y) {
                    count += state[i][j]
                }
            }
        }
        return count
    }
}

func generateInitialState(size: Int) -> [[Int]] {
    return Array(repeating: Array(repeating: Int.random(in: 0...1), count: size), count: size)
}

func main() {
    let size = 10
    let initialState = generateInitialState(size: size)
    let automaton = Automaton(size: size, initialState: initialState)
    while true {
        automaton.update()
    }
}

main()