func updateGrid(_ grid: [[Int]], _ size: Int) -> [[Int]] {
    var newGrid = Array(repeating: Array(repeating: 0, count: size), count: size)
    for i in 0..<size {
        for j in 0..<size {
            var neighbors = 0
            for x in max(0, i - 1)...min(size - 1, i + 1) {
                for y in max(0, j - 1)...min(size - 1, j + 1) {
                    if (x, y) != (i, j) {
                        neighbors += grid[x][y]
                    }
                }
            }
            newGrid[i][j] = neighbors == 3 ? 1 : neighbors == 2 ? grid[i][j] : 0
        }
    }
    return newGrid
}

func simulate(_ size: Int, _ steps: Int) -> [[Int]] {
    var grid = Array(repeating: Array(repeating: 0, count: size), count: size)
    for i in 0..<size {
        for j in 0..<size {
            grid[i][j] = i % 2 == 0 ? 1 : 0
        }
    }
    for _ in 0..<steps {
        grid = updateGrid(grid, size)
    }
    return grid
}

func main() {
    let size = 5
    let steps = 10
    let result = simulate(size, steps)
    for row in result {
        print(row.map { String($0) }.joined(separator: " "))
    }
}

main()