import Foundation

func update(_ grid: [[Int]], _ size: Int) -> [[Int]] {
    var new_grid = Array(repeating: Array(repeating: 0, count: size), count: size)
    for i in 0..<size {
        for j in 0..<size {
            var neighbors = 0
            for dx in [-1, 0, 1] {
                for dy in [-1, 0, 1] {
                    if dx == 0 && dy == 0 { continue }
                    neighbors += grid[(i + dx + size) % size][(j + dy + size) % size]
                }
            }
            new_grid[i][j] = neighbors == 3 ? 1 : neighbors == 2 ? grid[i][j] : 0
        }
    }
    return new_grid
}

func simulate(_ grid: [[Int]], _ size: Int) {
    for row in grid {
        print(row.map { $0 == 1 ? "#" : " " }.joined())
    }
    simulate(update(grid, size), size)
}

let size = 10
var grid = Array(repeating: Array(repeating: 0, count: size), count: size)
grid[size / 2][size / 2] = 1
simulate(grid, size)