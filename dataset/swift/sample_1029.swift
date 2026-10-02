import Foundation

func updateCell(_ grid: [[Int]], _ x: Int, _ y: Int, _ width: Int, _ height: Int) -> Int {
    var neighbors = 0
    for i in max(0, x - 1)...min(width - 1, x + 1) {
        for j in max(0, y - 1)...min(height - 1, y + 1) {
            if grid[i][j] == 1 {
                neighbors += 1
            }
        }
    }
    if grid[x][y] == 1 {
        return (2...3).contains(neighbors) ? 1 : 0
    } else {
        return neighbors == 3 ? 1 : 0
    }
}

func updateGrid(_ grid: [[Int]], _ width: Int, _ height: Int) -> [[Int]] {
    var newGrid = Array(repeating: Array(repeating: 0, count: height), count: width)
    for x in 0..<width {
        for y in 0..<height {
            newGrid[x][y] = updateCell(grid, x, y, width, height)
        }
    }
    return newGrid
}

func main() {
    let width = 10
    let height = 10
    var grid = Array(repeating: Array(repeating: 0, count: height), count: width)
    for x in 0..<width {
        for y in 0..<height {
            grid[x][y] = (x + y) % 2 == 0 ? 1 : 0
        }
    }
    while true {
        grid = updateGrid(grid, width, height)
    }
}

main()