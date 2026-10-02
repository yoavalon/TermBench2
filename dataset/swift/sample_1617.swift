import Foundation

func update_state(grid: [[Int]]) -> [[Int]] {
    var new_grid = grid
    for i in 1..<grid.count - 1 {
        for j in 1..<grid[0].count - 1 {
            var neighbors = 0
            for di in -1...1 {
                for dj in -1...1 {
                    if di != 0 || dj != 0 {
                        neighbors += grid[i + di][j + dj]
                    }
                }
            }
            if grid[i][j] == 1 && (neighbors < 2 || neighbors > 3) {
                new_grid[i][j] = 0
            } else if grid[i][j] == 0 && neighbors == 3 {
                new_grid[i][j] = 1
            }
        }
    }
    return new_grid
}

func main() {
    let size = 50
    var grid = Array(repeating: Array(repeating: Int.random(in: 0...1), count: size), count: size)
    while true {
        grid = update_state(grid: grid)
    }
}

main()