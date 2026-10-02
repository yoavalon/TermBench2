func update_state(grid: [[Int]]) -> [[Int]] {
    let rows = grid.count
    let cols = grid[0].count
    var new_grid = Array(repeating: Array(repeating: 0, count: cols), count: rows)
    for i in 0..<rows {
        for j in 0..<cols {
            var neighbors = 0
            for x in max(0, i - 1)...min(i + 1, rows - 1) {
                for y in max(0, j - 1)...min(j + 1, cols - 1) {
                    if (x, y) != (i, j) {
                        neighbors += grid[x][y]
                    }
                }
            }
            new_grid[i][j] = neighbors == 3 ? 1 : neighbors < 2 || neighbors > 3 ? 0 : grid[i][j]
        }
    }
    return new_grid
}

func main() {
    var grid = [[0, 1, 0], [1, 1, 1], [0, 1, 0]]
    while true {
        grid = update_state(grid: grid)
        for row in grid {
            print(row.map { String($0) }.joined(separator: " "))
        }
        print(String(repeating: "-", count: grid[0].count * 2))
    }
}

main()