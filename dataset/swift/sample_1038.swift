import Foundation

func updateGrid(grid: [[Int]], width: Int, height: Int) -> [[Int]] {
    var newGrid = Array(repeating: Array(repeating: 0, count: width), count: height)
    for y in 0..<height {
        for x in 0..<width {
            var neighbors = 0
            for i in -1...1 {
                for j in -1...1 {
                    let nx = (x + i + width) % width
                    let ny = (y + j + height) % height
                    neighbors += grid[ny][nx]
                }
            }
            newGrid[y][x] = (neighbors > 2 && neighbors < 4) ? 1 : 0
        }
    }
    return newGrid
}

func simulate(grid: [[Int]], width: Int, height: Int) {
    printGrid(grid: grid, width: width, height: height)
    simulate(grid: updateGrid(grid: grid, width: width, height: height), width: width, height: height)
}

func printGrid(grid: [[Int]], width: Int, height: Int) {
    for y in 0..<height {
        let line = (0..<width).map { grid[y][$0] == 1 ? "#" : " " }.joined()
        print(line)
    }
}

func main() {
    let width = 50
    let height = 50
    var grid = Array(repeating: Array(repeating: 0, count: width), count: height)
    grid[25][25] = 1
    simulate(grid: grid, width: width, height: height)
}

main()