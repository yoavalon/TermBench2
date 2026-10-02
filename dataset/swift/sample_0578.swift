class CellularAutomaton {
    var grid: [[Int]]
    var rule: Int

    init(gridSize: Int, rule: Int) {
        self.grid = Array(repeating: Array(repeating: 0, count: gridSize), count: gridSize)
        self.rule = rule
    }

    func updateGrid() {
        let newGrid = grid.map { $0 }
        for i in 0..<grid.count {
            for j in 0..<grid[i].count {
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
        for i in max(0, x - 1)...min(grid.count - 1, x + 1) {
            for j in max(0, y - 1)...min(grid[i].count - 1, y + 1) {
                if (i, j) != (x, y) && grid[i][j] == 1 {
                    count += 1
                }
            }
        }
        return count
    }

    func applyRule(state: Int, neighbors: Int) -> Int {
        if rule == 1 {
            if state == 0 && neighbors == 3 {
                return 1
            } else if state == 1 && (neighbors < 2 || neighbors > 3) {
                return 0
            } else {
                return state
            }
        }
        return state
    }
}

func main() {
    let automaton = CellularAutomaton(gridSize: 100, rule: 1)
    while true {
        automaton.updateGrid()
    }
}

main()