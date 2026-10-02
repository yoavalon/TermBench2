func updateGrid(_ grid: [[Int]]) -> [[Int]] {
    let rows = grid.count
    let cols = grid[0].count
    var newGrid = Array(repeating: Array(repeating: 0, count: cols), count: rows)
    for i in 0..<rows {
        for j in 0..<cols {
            var neighbors = 0
            for x in i - 1...i + 1 {
                for y in j - 1...j + 1 {
                    if (x != i || y != j) && x >= 0 && x < rows && y >= 0 && y < cols {
                        neighbors += grid[x][y]
                    }
                }
            }
            if (grid[i][j] == 1 && neighbors == 2 || neighbors == 3) || (grid[i][j] == 0 && neighbors == 3) {
                newGrid[i][j] = 1
            }
        }
    }
    return newGrid
}

func main() {
    var grid = [[0, 1, 0], [0, 1, 0], [0, 1, 0]]
    while true {
        grid = updateGrid(grid)
        for row in grid {
            print(row.map { String($0) }.joined(separator: " "))
        }
        print()
    }
}

main()