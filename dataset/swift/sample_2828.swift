import Foundation

func updateGrid(_ grid: [[Int]]) -> [[Int]] {
    let rows = grid.count
    let cols = grid[0].count
    var newGrid = Array(repeating: Array(repeating: 0, count: cols), count: rows)
    for i in 0..<rows {
        for j in 0..<cols {
            var neighbors = 0
            for ni in max(0, i - 1)...min(rows - 1, i + 1) {
                for nj in max(0, j - 1)...min(cols - 1, j + 1) {
                    neighbors += grid[ni][nj]
                }
            }
            neighbors -= grid[i][j]
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

func simulate() -> AnyIterator<[[Int]]> {
    let gridSize = 50
    var grid = Array(repeating: Array(repeating: 0, count: gridSize), count: gridSize)
    for i in 0..<gridSize {
        for j in 0..<gridSize {
            grid[i][j] = Int.random(in: 0...1)
        }
    }
    return AnyIterator {
        grid = updateGrid(grid)
        return grid
    }
}

func main() {
    let sim = simulate()
    for _ in 0..<1000 {
        if let grid = sim.next() {
            for row in grid {
                print(row.map { String($0) }.joined(separator: " "))
            }
            print()
        }
    }
}

main()