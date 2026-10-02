import Foundation

func initializeGrid(size: Int) -> [[Int]] {
    var grid = Array(repeating: Array(repeating: 0, count: size), count: size)
    grid[size / 2][size / 2] = 1
    return grid
}

func applyBoundaryConditions(grid: inout [[Int]]) {
    let size = grid.count
    for i in 0..<size {
        grid[0][i] = 0
        grid[size - 1][i] = 0
        grid[i][0] = 0
        grid[i][size - 1] = 0
    }
}

func updateGrid(grid: [[Int]]) -> [[Int]] {
    var newGrid = grid
    let size = grid.count
    for i in 1..<(size - 1) {
        for j in 1..<(size - 1) {
            let neighbors = (i - 1...i + 1).flatMap { x in
                (j - 1...j + 1).map { y in
                    grid[x][y]
                }
            }.reduce(0, +) - grid[i][j]
            if grid[i][j] == 1 {
                if neighbors < 2 || neighbors > 3 {
                    newGrid[i][j] = 0
                }
            } else if neighbors == 3 {
                newGrid[i][j] = 1
            }
        }
    }
    return newGrid
}

func simulate(steps: Int) -> [[Int]] {
    let size = 50
    var grid = initializeGrid(size: size)
    applyBoundaryConditions(grid: &grid)
    for _ in 0..<steps {
        grid = updateGrid(grid: grid)
        applyBoundaryConditions(grid: &grid)
    }
    return grid
}

func main() {
    let steps = 100
    let result = simulate(steps: steps)
    for row in result {
        print(row)
    }
}

main()