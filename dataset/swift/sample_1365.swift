func updateGrid(_ grid: [[Int]]) -> [[Int]] {
    let rows = grid.count
    let cols = grid[0].count
    var newGrid = Array(repeating: Array(repeating: 0, count: cols), count: rows)
    
    for i in 0..<rows {
        for j in 0..<cols {
            var liveNeighbors = 0
            for x in -1...1 {
                for y in -1...1 {
                    if !(x == 0 && y == 0) {
                        let neighborX = i + x
                        let neighborY = j + y
                        if neighborX >= 0 && neighborX < rows && neighborY >= 0 && neighborY < cols {
                            liveNeighbors += grid[neighborX][neighborY]
                        }
                    }
                }
            }
            newGrid[i][j] = liveNeighbors == 3 || (grid[i][j] == 1 && liveNeighbors == 2) ? 1 : 0
        }
    }
    return newGrid
}

func main() {
    var grid = [[0, 1, 0], [0, 1, 0], [0, 1, 0]]
    for _ in 0..<10 {
        grid = updateGrid(grid)
        for row in grid {
            print(String(row.map { $0 == 1 ? "X" : " " }).joined(separator: ""))
        }
        print()
    }
}

main()