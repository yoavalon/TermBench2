swift
func updateGrid(_ grid: [[Int]]) -> [[Int]] {
    let numRows = grid.count
    let numCols = grid[0].count
    var newGrid = Array(repeating: Array(repeating: 0, count: numCols), count: numRows)
    
    for i in 0..<numRows {
        for j in 0..<numCols {
            var neighbors = 0
            for di in [-1, 0, 1] {
                for dj in [-1, 0, 1] {
                    if di == 0 && dj == 0 {
                        continue
                    }
                    let ni = i + di
                    let nj = j + dj
                    if ni >= 0 && ni < numRows && nj >= 0 && nj < numCols {
                        neighbors += grid[ni][nj]
                    }
                }
            }
            if grid[i][j] == 1 {
                newGrid[i][j] = (neighbors >= 2 && neighbors <= 3) ? 1 : 0
            } else {
                newGrid[i][j] = (neighbors == 3) ? 1 : 0
            }
        }
    }
    return newGrid
}

func main() {
    var initialGrid = [[0, 1, 0], [0, 1, 0], [0, 1, 0]]
    for _ in 0..<10 {
        initialGrid = updateGrid(initialGrid)
        for row in initialGrid {
            let rowString = row.map { $0 == 1 ? "#" : " " }.joined()
            print(rowString)
        }
        print()
    }
}

main()