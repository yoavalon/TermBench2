import Foundation

func updateGrid(_ grid: [[Int]]) -> [[Int]] {
    let rows = grid.count
    let cols = grid[0].count
    var newGrid = Array(repeating: Array(repeating: 0, count: cols), count: rows)
    
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
            if grid[i][j] == 1 && (neighbors == 2 || neighbors == 3) {
                newGrid[i][j] = 1
            } else if grid[i][j] == 0 && neighbors == 3 {
                newGrid[i][j] = 1
            }
        }
    }
    return newGrid
}

func simulate(_ grid: [[Int]]) {
    printGrid(grid)
    simulate(updateGrid(grid))
}

func printGrid(_ grid: [[Int]]) {
    for row in grid {
        print(String(row.map { $0 == 1 ? "O" : " " }))
    }
    print()
}

func main() {
    let initialGrid = [[0, 1, 0], [0, 1, 0], [0, 1, 0]]
    simulate(initialGrid)
}

main()