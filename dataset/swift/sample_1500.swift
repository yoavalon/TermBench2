class AutomataSimulator {
    var grid: [[Int]]
    var rule: [[Int]: [Int]]
    var size: Int

    init(size: Int, rule: [[Int]: [Int]]) {
        self.grid = Array(repeating: Array(repeating: 0, count: size), count: size)
        self.rule = rule
        self.size = size
    }

    func update() {
        var newGrid = Array(repeating: Array(repeating: 0, count: size), count: size)
        for i in 0..<size {
            for j in 0..<size {
                let state = grid[i][j]
                let neighbors = countNeighbors(x: i, y: j)
                let newState = applyRule(state: state, neighbors: neighbors)
                newGrid[i][j] = newState
            }
        }
        grid = newGrid
    }

    func countNeighbors(x: Int, y: Int) -> Int {
        var count = 0
        for i in x - 1...x + 1 {
            for j in y - 1...y + 1 {
                if 0 <= i && i < size && 0 <= j && j < size && !(i == x && j == y) {
                    count += grid[i][j]
                }
            }
        }
        return count
    }

    func applyRule(state: Int, neighbors: Int) -> Int {
        return rule[state]![neighbors]!
    }
}

func main() {
    let size = 10
    let rule: [[Int]: [Int]] = [
        0: [0: 0, 1: 1, 2: 1, 3: 1, 4: 0, 5: 0, 6: 0, 7: 0, 8: 0],
        1: [0: 0, 1: 0, 2: 0, 3: 1, 4: 0, 5: 0, 6: 0, 7: 0, 8: 0]
    ]
    let automata = AutomataSimulator(size: size, rule: rule)
    for _ in 0..<100 {
        automata.update()
    }
    print(automata.grid)
}

main()