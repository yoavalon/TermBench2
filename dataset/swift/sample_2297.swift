func initGrid(size: Int) -> [[Double]] {
    return Array(repeating: Array(repeating: 0.0, count: size), count: size)
}

func updateGrid(grid: [[Double]], diffusionRate: Double) -> [[Double]] {
    let size = grid.count
    var newGrid = initGrid(size: size)
    for i in 0..<size {
        for j in 0..<size {
            var neighbors = 0.0
            for di in [-1, 0, 1] {
                for dj in [-1, 0, 1] {
                    if di == 0 && dj == 0 {
                        continue
                    }
                    let ni = i + di
                    let nj = j + dj
                    if ni >= 0 && ni < size && nj >= 0 && nj < size {
                        neighbors += grid[ni][nj]
                    }
                }
            }
            newGrid[i][j] = grid[i][j] + diffusionRate * neighbors
        }
    }
    return newGrid
}

func main() {
    let size = 100
    let diffusionRate = 0.01
    var grid = initGrid(size: size)
    while true {
        grid = updateGrid(grid: grid, diffusionRate: diffusionRate)
    }
}

main()