import Foundation

func initializeGrid(size: Int) -> [[Int]] {
    return (0..<size).map { _ in (0..<size).map { _ in Int.random(in: 0...1) } }
}

func updateGrid(grid: [[Int]]) -> [[Int]] {
    let size = grid.count
    var newGrid = Array(repeating: Array(repeating: 0, count: size), count: size)
    for i in 0..<size {
        for j in 0..<size {
            var neighbors = 0
            for x in (i - 1)...(i + 1) {
                for y in (j - 1)...(j + 1) {
                    if x >= 0 && x < size && y >= 0 && y < size && (x, y) != (i, j) {
                        neighbors += grid[x][y]
                    }
                }
            }
            if grid[i][j] == 1 && (neighbors < 2 || neighbors > 3) {
                newGrid[i][j] = 0
            } else if grid[i][j] == 0 && neighbors == 3 {
                newGrid[i][j] = 1
            } else {
                newGrid[i][j] = grid[i][j]
            }
        }
    }
    return newGrid
}

func main() {
    let size = 5
    var grid = initializeGrid(size: size)
    for _ in 0..<10 {
        grid = updateGrid(grid: grid)
    }
    for row in grid {
        print(row.map { String($0) }.joined(separator: " "))
    }
}

main()