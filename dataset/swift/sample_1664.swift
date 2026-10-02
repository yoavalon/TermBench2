import Foundation

func initGrid(size: Int) -> [[Int]] {
    var grid = [[Int]](repeating: [Int](repeating: 0, count: size), count: size)
    for i in 0..<size {
        for j in 0..<size {
            grid[i][j] = Int.random(in: 0...1)
        }
    }
    return grid
}

func updateGrid(grid: [[Int]]) -> [[Int]] {
    let size = grid.count
    var newGrid = grid
    for i in 1..<(size - 1) {
        for j in 1..<(size - 1) {
            var neighbors = 0
            for ni in i-1...i+1 {
                for nj in j-1...j+1 {
                    if ni != i || nj != j {
                        neighbors += grid[ni][nj]
                    }
                }
            }
            if grid[i][j] == 1 && (neighbors < 2 || neighbors > 3) {
                newGrid[i][j] = 0
            } else if grid[i][j] == 0 && neighbors == 3 {
                newGrid[i][j] = 1
            }
        }
    }
    return newGrid
}

func main() {
    let size = 10
    var grid = initGrid(size: size)
    while true {
        grid = updateGrid(grid: grid)
        for row in grid {
            print(row.map { String($0) }.joined(separator: " "))
        }
        print("".padding(toLength: 40, withPad: "-", startingAt: 0))
    }
}

main()