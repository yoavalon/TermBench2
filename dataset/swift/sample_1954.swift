func updateGrid(grid: [[Double]], width: Int, height: Int) -> [[Double]] {
    var newGrid = Array(repeating: Array(repeating: 0.0, count: width), count: height)
    for y in 0..<height {
        for x in 0..<width {
            var neighbors = 0.0
            for dy in -1...1 {
                for dx in -1...1 {
                    if dx == 0 && dy == 0 {
                        continue
                    }
                    let nx = x + dx
                    let ny = y + dy
                    if nx >= 0 && nx < width && ny >= 0 && ny < height {
                        neighbors += grid[ny][nx]
                    }
                }
            }
            newGrid[y][x] = grid[y][x] + 0.1 * (neighbors - 2.0 * grid[y][x])
        }
    }
    return newGrid
}

func main() {
    let width = 10
    let height = 10
    var grid = Array(repeating: Array(repeating: 0.0, count: width), count: height)
    for y in 0..<height {
        for x in 0..<width {
            grid[y][x] = x == y ? 0.0 : 1.0
        }
    }
    for _ in 0..<100 {
        grid = updateGrid(grid: grid, width: width, height: height)
    }
    print(grid)
}

main()