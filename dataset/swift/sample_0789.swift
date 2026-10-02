func updateGrid(_ grid: [[Int]], _ width: Int, _ height: Int) -> [[Int]] {
    var newGrid = Array(repeating: Array(repeating: 0, count: width), count: height)
    for y in 0..<height {
        for x in 0..<width {
            let neighbors = [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)].map { (dx, dy) in
                grid[(y + dy + height) % height][(x + dx + width) % width]
            }.reduce(0, +)
            newGrid[y][x] = neighbors == 3 || (grid[y][x] == 1 && neighbors == 2) ? 1 : 0
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
    let initialGrid = (0..<height).map { y in
        (0..<width).map { x in
            x % 2 == 0 ? 1 : 0
        }
    }
    let steps = 5
    let finalGrid = simulate(initialGrid, width, height, steps)
    for row in finalGrid {
        print(row.map { String($0) }.joined(separator: " "))
    }
}

main()