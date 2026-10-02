swift
func updateGrid(_ grid: [[Double]], _ width: Int, _ height: Int) -> [[Double]] {
    var newGrid = [[Double]](repeating: [Double](repeating: 0.0, count: width), count: height)
    for y in 0..<height {
        for x in 0..<width {
            var neighbors: [Double] = []
            for dy in [-1, 0, 1] {
                for dx in [-1, 0, 1] {
                    if dy != 0 || dx != 0 {
                        neighbors.append(grid[(y + dy + height) % height][(x + dx + width) % width])
                    }
                }
            }
            newGrid[y][x] = neighbors.reduce(0, +) / Double(neighbors.count)
        }
    }
    return newGrid
}

func simulate(_ width: Int, _ height: Int, _ steps: Int) -> [[Double]] {
    var grid = [[Double]](repeating: [Double](repeating: 0.0, count: width), count: height)
    for y in 0..<height {
        for x in 0..<width {
            grid[y][x] = Double(x + y)
        }
    }
    for _ in 0..<steps {
        grid = updateGrid(grid, width, height)
    }
    return grid
}

func main() {
    let width = 10
    let height = 10
    let steps = 5
    let finalGrid = simulate(width, height, steps)
    for row in finalGrid {
        print(row)
    }
}

main()