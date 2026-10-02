func fluidDynamics(_ grid: [[Int]]) -> [[Int]] {
    let size = grid.count
    var nextGrid = Array(repeating: Array(repeating: 0, count: size), count: size)
    for i in 0..<size {
        for j in 0..<size {
            let neighbors = (max(0, i - 1)...min(size - 1, i + 1)).flatMap { x in
                (max(0, j - 1)...min(size - 1, j + 1)).map { y in
                    grid[x][y]
                }
            }.reduce(0, +)
            nextGrid[i][j] = neighbors > 4 ? 1 : 0
        }
    }
    return fluidDynamics(nextGrid)
}

var grid = Array(repeating: Array(repeating: 0, count: 10), count: 10)
grid[5][5] = 1
_ = fluidDynamics(grid)