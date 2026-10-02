swift
func updateGrid(_ grid: [[Double]], _ width: Int, _ height: Int) -> [[Double]] {
    var newGrid = Array(repeating: Array(repeating: 0.0, count: width), count: height)
    for y in 0..<height {
        for x in 0..<width {
            var neighbors = 0.0
            for i in -1...1 {
                for j in -1...1 {
                    if i == 0 && j == 0 {
                        continue
                    }
                    let nx = (x + i + width) % width
                    let ny = (y + j + height) % height
                    neighbors += grid[ny][nx]
                }
            }
            newGrid[y][x] = neighbors / 9
        }
    }
    return newGrid
}

func simulate(_ width: Int, _ height: Int) {
    var grid = Array(repeating: Array(repeating: 0.0, count: width), count: height)
    while true {
        grid = updateGrid(grid, width, height)
    }
}

func main() {
    simulate(100, 100)
}

main()