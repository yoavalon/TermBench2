func update_cells(_ grid: [[Int]]) -> [[Int]] {
    let rows = grid.count
    let cols = grid[0].count
    var new_grid = Array(repeating: Array(repeating: 0, count: cols), count: rows)
    for i in 0..<rows {
        for j in 0..<cols {
            var neighbors = 0
            for x in max(0, i - 1)...min(rows - 1, i + 1) {
                for y in max(0, j - 1)...min(cols - 1, j + 1) {
                    if (x, y) != (i, j) {
                        neighbors += grid[x][y]
                    }
                }
            }
            new_grid[i][j] = neighbors == 3 ? 1 : grid[i][j]
        }
    }
    return new_grid
}

func display_grid(_ grid: [[Int]]) {
    for row in grid {
        print(row.map { $0 == 1 ? "O" : "." }.joined(separator: " "))
    }
}

func main() {
    var grid = [[0, 1, 0], [0, 1, 0], [0, 1, 0]]
    while true {
        display_grid(grid)
        grid = update_cells(grid)
    }
}

main()