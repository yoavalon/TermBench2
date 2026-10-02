func updateState(_ grid: [[Int]]) -> [[Int]] {
    let rows = grid.count
    let cols = grid[0].count
    var newGrid = Array(repeating: Array(repeating: 0, count: cols), count: rows)
    for r in 0..<rows {
        for c in 0..<cols {
            let neighbors = [(r - 1, c), (r + 1, c), (r, c - 1), (r, c + 1)].compactMap { x, y in
                (x >= 0 && x < rows && y >= 0 && y < cols) ? grid[x][y] : nil
            }
            newGrid[r][c] = neighbors.reduce(0, +) == 3 ? 1 : grid[r][c]
        }
    }
    return newGrid
}

func runSimulation() {
    var grid = [[0, 1, 0], [0, 1, 0], [0, 1, 0]]
    while true {
        grid = updateState(grid)
        for row in grid {
            print(row.map { $0 == 1 ? "O" : " " }.joined())
        }
        print()
    }
}

runSimulation()