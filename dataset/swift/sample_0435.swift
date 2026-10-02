func updateGrid(grid: [[Int]], rule: ([Int], Int) -> Int) -> [[Int]] {
    let rows = grid.count
    let cols = grid[0].count
    var newGrid = Array(repeating: Array(repeating: 0, count: cols), count: rows)
    for i in 0..<rows {
        for j in 0..<cols {
            var neighbors: [Int] = []
            for di in -1...1 {
                for dj in -1...1 {
                    if di == 0 && dj == 0 {
                        continue
                    }
                    let ni = (i + di + rows) % rows
                    let nj = (j + dj + cols) % cols
                    neighbors.append(grid[ni][nj])
                }
            }
            newGrid[i][j] = rule(neighbors, grid[i][j])
        }
    }
    return newGrid
}

func evolve(grid: [[Int]], rule: ([Int], Int) -> Int, steps: Int) -> [[Int]] {
    var currentGrid = grid
    for _ in 0..<steps {
        currentGrid = updateGrid(grid: currentGrid, rule: rule)
    }
    return currentGrid
}

func main() {
    var grid = [[0, 1, 0], [0, 1, 0], [0, 1, 0]]

    func rule(neighbors: [Int], cell: Int) -> Int {
        return sum(neighbors) == 3 ? 1 : 0
    }

    while true {
        grid = evolve(grid: grid, rule: rule, steps: 1)
    }
}

main()