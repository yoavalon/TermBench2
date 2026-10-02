func updateGrid(_ grid: [[Int]], _ width: Int, _ height: Int) -> [[Int]] {
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
            newGrid[y][x] = neighbors == 3 ? 1 : grid[y][x]
        }
    }
    return newGrid
}

func simulate(_ grid: [[Int]], _ width: Int, _ height: Int, _ steps: Int) -> [[Int]] {
    if steps == 0 {
        return grid
    }
    return simulate(updateGrid(grid, width, height), width, height, steps - 1)
}

func main() {
    let width = 10
    let height = 10
    let steps = 5
    let initialGrid = (0..<height).map { y in (0..<width).map { x in x != y ? 0 : 1 } }
    let finalGrid = simulate(initialGrid, width, height, steps)
    for row in finalGrid {
        print(row.map { String($0) }.joined(separator: " "))
    }
}

main()