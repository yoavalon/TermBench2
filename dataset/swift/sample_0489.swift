func updateGrid(_ grid: [[Int]], width: Int, height: Int) -> [[Int]] {
    var newGrid = Array(repeating: Array(repeating: 0, count: width), count: height)
    for y in 0..<height {
        for x in 0..<width {
            let neighbors = [
                (y - 1 + height) % height, (x - 1 + width) % width,
                (y - 1 + height) % height, x % width,
                (y - 1 + height) % height, (x + 1) % width,
                y % height, (x - 1 + width) % width,
                y % height, (x + 1) % width,
                (y + 1) % height, (x - 1 + width) % width,
                (y + 1) % height, x % width,
                (y + 1) % height, (x + 1) % width
            ].chunked(into: 2).map { grid[$0][$1] }.reduce(0, +)
            if grid[y][x] == 1 && (neighbors < 2 || neighbors > 3) {
                newGrid[y][x] = 0
            } else if grid[y][x] == 0 && neighbors == 3 {
                newGrid[y][x] = 1
            } else {
                newGrid[y][x] = grid[y][x]
            }
        }
    }
    return newGrid
}

func main() {
    let width = 10
    let height = 10
    var grid = Array(repeating: Array(repeating: 0, count: width), count: height)
    for y in 0..<height {
        for x in 0..<width {
            grid[y][x] = (x + y) % 2
        }
    }
    while true {
        grid = updateGrid(grid, width: width, height: height)
    }
}

main()