func updateGrid(_ grid: [[Int]], width: Int, height: Int) -> [[Int]] {
    var newGrid = Array(repeating: Array(repeating: 0, count: width), count: height)
    for y in 0..<height {
        for x in 0..<width {
            var neighbors = 0
            for dx in -1...1 {
                for dy in -1...1 {
                    if dx == 0 && dy == 0 {
                        continue
                    }
                    neighbors += grid[(y + dy + height) % height][(x + dx + width) % width]
                }
            }
            if grid[y][x] == 1 {
                newGrid[y][x] = neighbors == 2 || neighbors == 3 ? 1 : 0
            } else {
                newGrid[y][x] = neighbors == 3 ? 1 : 0
            }
        }
    }
    return newGrid
}

func main() {
    let width = 50
    let height = 50
    var grid = Array(repeating: Array(repeating: 0, count: width), count: height)
    for y in 0..<height {
        for x in 0..<width {
            grid[y][x] = (x + y) % 2 == 0 ? 1 : 0
        }
    }
    while true {
        grid = updateGrid(grid, width: width, height: height)
    }
}

main()