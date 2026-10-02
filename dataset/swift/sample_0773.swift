import Foundation

func updateGrid(_ grid: [[Int]], width: Int, height: Int) -> [[Int]] {
    var newGrid = Array(repeating: Array(repeating: 0, count: width), count: height)
    for y in 0..<height {
        for x in 0..<width {
            var neighbors = 0
            for ny in max(0, y - 1)...min(height - 1, y + 1) {
                for nx in max(0, x - 1)...min(width - 1, x + 1) {
                    neighbors += grid[ny][nx]
                }
            }
            neighbors -= grid[y][x]
            newGrid[y][x] = (neighbors == 3 || (neighbors == 2 && grid[y][x] == 1)) ? 1 : 0
        }
    }
    return newGrid
}

func simulate(_ grid: [[Int]], width: Int, height: Int, steps: Int) -> [[Int]] {
    var currentGrid = grid
    for _ in 0..<steps {
        currentGrid = updateGrid(currentGrid, width: width, height: height)
    }
    return currentGrid
}

func main() {
    let width = 10
    let height = 10
    let steps = 5
    var initialGrid = Array(repeating: Array(repeating: 0, count: width), count: height)
    initialGrid[5][5] = 1
    let result = simulate(initialGrid, width: width, height: height, steps: steps)
    for row in result {
        let line = row.map { $0 == 1 ? "O" : " " }.joined()
        print(line)
    }
}

main()