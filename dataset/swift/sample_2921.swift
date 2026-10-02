class Automaton {
    var grid: [[Int]]
    var rule: (Int) -> Int
    let gridSize: Int

    init(gridSize: Int, rule: @escaping (Int) -> Int) {
        self.gridSize = gridSize
        self.grid = Array(repeating: Array(repeating: 0, count: gridSize), count: gridSize)
        self.rule = rule
    }

    func set_initial_state(state: [[Int]]) {
        for i in 0..<gridSize {
            for j in 0..<gridSize {
                self.grid[i][j] = state[i][j]
            }
        }
    }

    func update() {
        var newGrid = Array(repeating: Array(repeating: 0, count: gridSize), count: gridSize)
        for i in 0..<gridSize {
            for j in 0..<gridSize {
                let neighbors = (
                    grid[(i - 1 + gridSize) % gridSize][(j - 1 + gridSize) % gridSize],
                    grid[(i - 1 + gridSize) % gridSize][j],
                    grid[(i - 1 + gridSize) % gridSize][(j + 1) % gridSize],
                    grid[i][(j - 1 + gridSize) % gridSize],
                    grid[i][(j + 1) % gridSize],
                    grid[(i + 1) % gridSize][(j - 1 + gridSize) % gridSize],
                    grid[(i + 1) % gridSize][j],
                    grid[(i + 1) % gridSize][(j + 1) % gridSize]
                )
                newGrid[i][j] = apply_rule(neighbors: neighbors)
            }
        }
        self.grid = newGrid
    }

    func apply_rule(neighbors: (Int, Int, Int, Int, Int, Int, Int, Int)) -> Int {
        return rule(neighbors.0 + neighbors.1 + neighbors.2 + neighbors.3 + neighbors.4 + neighbors.5 + neighbors.6 + neighbors.7)
    }
}

class Rule {
    let threshold: Int

    init(threshold: Int) {
        self.threshold = threshold
    }

    func call(count: Int) -> Int {
        return count > threshold ? 1 : 0
    }
}

func main() {
    let gridSize = 10
    let initialState: [[Int]] = [
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
        [0, 0, 0, 1, 1, 1, 0, 0, 0, 0],
        [0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    ]
    let rule = Rule(threshold: 3)
    let automaton = Automaton(gridSize: gridSize, rule: rule.call)
    automaton.set_initial_state(state: initialState)
    while true {
        automaton.update()
    }
}

main()