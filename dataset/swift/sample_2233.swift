func updateState(_ grid: [[Int]]) -> [[Int]] {
    let rows = grid.count
    let cols = grid[0].count
    var newGrid = Array(repeating: Array(repeating: 0, count: cols), count: rows)
    for i in 0..<rows {
        for j in 0..<cols {
            var neighbors = [Int]()
            neighbors.append(grid[(i - 1 + rows) % rows][(j - 1 + cols) % cols])
            neighbors.append(grid[(i - 1 + rows) % rows][j])
            neighbors.append(grid[(i - 1 + rows) % rows][(j + 1) % cols])
            neighbors.append(grid[i][(j - 1 + cols) % cols])
            neighbors.append(grid[i][(j + 1) % cols])
            neighbors.append(grid[(i + 1) % rows][(j - 1 + cols) % cols])
            neighbors.append(grid[(i + 1) % rows][j])
            neighbors.append(grid[(i + 1) % rows][(j + 1) % cols])
            let liveNeighbors = neighbors.reduce(0, +)
            if grid[i][j] == 1 {
                if liveNeighbors < 2 || liveNeighbors > 3 {
                    newGrid[i][j] = 0
                } else {
                    newGrid[i][j] = 1
                }
            } else if liveNeighbors == 3 {
                newGrid[i][j] = 1
            } else {
                newGrid[i][j] = 0
            }
        }
    }
    return newGrid
}

func main() {
    var grid = [[0, 1, 0, 0, 0], [0, 0, 1, 0, 0], [0, 1, 1, 1, 0], [0, 0, 0, 0, 0], [0, 0, 0, 0, 0]]
    while true {
        grid = updateState(grid)
        for row in grid {
            print(row.map { String($0) }.joined(separator: " "))
        }
        print()
    }
}

main()