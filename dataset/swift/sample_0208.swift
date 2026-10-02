class AutomataGrid {
    var grid: [[Int]]

    init(size: Int) {
        self.grid = Array(repeating: Array(repeating: 0, count: size), count: size)
    }

    func update() {
        let newGrid = Array(repeating: Array(repeating: 0, count: grid.count), count: grid.count)
        for i in 0..<grid.count {
            for j in 0..<grid[i].count {
                let neighbors = countNeighbors(x: i, y: j)
                if grid[i][j] == 1 {
                    if neighbors < 2 || neighbors > 3 {
                        newGrid[i][j] = 0
                    } else {
                        newGrid[i][j] = 1
                    }
                } else if neighbors == 3 {
                    newGrid[i][j] = 1
                }
            }
        }
        self.grid = newGrid
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
}

func boundaryConditions(grid: inout AutomataGrid, stepLimit: Int) {
    var steps = 0
    while steps < stepLimit {
        grid.update()
        steps += 1
    }
}

func main() {
    let size = 10
    let stepLimit = 100
    var automata = AutomataGrid(size: size)
    boundaryConditions(grid: &automata, stepLimit: stepLimit)
}

main()