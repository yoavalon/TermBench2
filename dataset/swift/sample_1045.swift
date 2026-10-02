func updateGrid(_ grid: [[Int]]) -> [[Int]] {
    let rows = grid.count
    let cols = grid[0].count
    var newGrid = Array(repeating: Array(repeating: 0, count: cols), count: rows)
    
    for i in 0..<rows {
        for j in 0..<cols {
            let neighbors = [
                grid[(i - 1 + rows) % rows][(j - 1 + cols) % cols], grid[(i - 1 + rows) % rows][j], grid[(i - 1 + rows) % rows][(j + 1) % cols],
                grid[i][(j - 1 + cols) % cols], grid[i][(j + 1) % cols],
                grid[(i + 1) % rows][(j - 1 + cols) % cols], grid[(i + 1) % rows][j], grid[(i + 1) % rows][(j + 1) % cols]
            ]
            newGrid[i][j] = neighbors.reduce(0, +) / 8
        }
    }
    return newGrid
}

func simulate(_ grid: inout [[Int]]) {
    while true {
        grid = updateGrid(grid)
        for row in grid {
            print(row.map { String($0) }.joined(separator: " "))
        }
        print()
    }
}

func main() {
    var initialGrid = [[1, 0, 1], [0, 1, 0], [1, 0, 1]]
    simulate(&initialGrid)
}

main()