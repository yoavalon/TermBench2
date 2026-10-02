import Foundation

func updateGrid(grid: [[Int]], size: Int) -> [[Int]] {
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
            newGrid[i][j] = neighbors == 3 || (neighbors == 2 && grid[i][j]) ? 1 : 0
        }
    }
    return newGrid
}

func simulate(grid: [[Int]], size: Int, steps: Int) -> [[Int]] {
    if steps == 0 {
        return grid
    }
    return simulate(grid: updateGrid(grid: grid, size: size), size: size, steps: steps - 1)
}

func main() {
    let size = 10
    var initialGrid = Array(repeating: Array(repeating: 0, count: size), count: size)
    initialGrid[5][5] = 1
    initialGrid[5][6] = 1
    initialGrid[6][5] = 1
    initialGrid[6][6] = 1
    let finalGrid = simulate(grid: initialGrid, size: size, steps: 10)
    for row in finalGrid {
        print(row.map { String($0) }.joined(separator: " "))
    }
}

main()