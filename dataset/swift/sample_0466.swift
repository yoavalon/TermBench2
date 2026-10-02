func updateCell(_ grid: [[Int]], _ i: Int, _ j: Int, _ size: Int) -> Int {
    var neighbors = 0
    for x in i - 1...i + 1 {
        for y in j - 1...j + 1 {
            if 0 <= x && x < size && 0 <= y && y < size && (x != i || y != j) {
                neighbors += grid[x][y]
            }
        }
    }
    return neighbors == 3 || (grid[i][j] == 1 && neighbors == 2) ? 1 : 0
}

func step(_ grid: [[Int]]) -> [[Int]] {
    let size = grid.count
    var newGrid = Array(repeating: Array(repeating: 0, count: size), count: size)
    for i in 0..<size {
        for j in 0..<size {
            newGrid[i][j] = updateCell(grid, i, j, size)
        }
    }
    return newGrid
}

func main() {
    let size = 10
    var grid = Array(repeating: Array(repeating: 0, count: size), count: size)
    grid[1][1] = 1
    grid[2][2] = 1
    grid[2][1] = 1
    while true {
        grid = step(grid)
    }
}

main()