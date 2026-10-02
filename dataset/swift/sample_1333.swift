import Foundation

func updateGrid(_ grid: [[Int]]) -> [[Int]] {
    let gridSize = grid.count
    var newGrid = grid.map { $0.map { $0 } }
    for i in 1..<gridSize - 1 {
        for j in 1..<gridSize - 1 {
            var neighbors = 0
            for di in -1...1 {
                for dj in -1...1 {
                    neighbors += grid[i + di][j + dj]
                }
            }
            neighbors -= grid[i][j]
            if grid[i][j] != 0 && (neighbors < 2 || neighbors > 3) {
                newGrid[i][j] = 0
            } else if grid[i][j] == 0 && neighbors == 3 {
                newGrid[i][j] = 1
            }
        }
    }
    return newGrid
}

func simulate(_ grid: [[Int]], _ steps: Int) -> [[Int]] {
    var currentGrid = grid
    for _ in 0..<steps {
        currentGrid = updateGrid(currentGrid)
    }
    return currentGrid
}

func main() {
    let size = 50
    var grid = Array(repeating: Array(repeating: 0, count: size), count: size)
    for i in 20..<25 {
        for j in 20..<25 {
            grid[i][j] = Int.random(in: 0...1)
        }
    }
    let finalGrid = simulate(grid, 100)
    for row in finalGrid {
        print(row)
    }
}

main()