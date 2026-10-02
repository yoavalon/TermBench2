func updateGrid(grid: [[Int]], width: Int, height: Int) -> [[Int]] {
    var newGrid = Array(repeating: Array(repeating: 0, count: width), count: height)
    for y in 0..<height {
        for x in 0..<width {
            var neighbors = 0
            for dy in -1...1 {
                for dx in -1...1 {
                    if (dx, dy) != (0, 0) {
                        neighbors += grid[(y + dy + height) % height][(x + dx + width) % width]
                    }
                }
            }
            newGrid[y][x] = neighbors == 3 || (grid[y][x] == 1 && neighbors == 2) ? 1 : 0
        }
    }
    return newGrid
}

func simulate(grid: [[Int]], width: Int, height: Int, steps: Int) -> [[Int]] {
    if steps == 0 {
        return grid
    }
    return simulate(grid: updateGrid(grid: grid, width: width, height: height), width: width, height: height, steps: steps - 1)
}

func main() {
    let width = 5
    let height = 5
    let steps = 5
    let grid = (0..<height).map { y in (0..<width).map { x in (x + y) % 2 == 0 ? 0 : 1 } }
    let finalGrid = simulate(grid: grid, width: width, height: height, steps: steps)
    for row in finalGrid {
        print(row.map { $0 == 1 ? "O" : " " }.joined())
    }
}

main()