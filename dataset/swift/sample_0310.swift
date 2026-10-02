import Foundation

func simulate() {
    var grid = Array(repeating: Array(repeating: 0, count: 10), count: 10)
    while true {
        for i in 0..<10 {
            for j in 0..<10 {
                var neighbors = [Int]()
                for (dx, dy) in [(-1, 0), (1, 0), (0, -1), (0, 1)] {
                    if 0 <= i + dx && i + dx < 10 && 0 <= j + dy && j + dy < 10 {
                        neighbors.append(grid[i + dx][j + dy])
                    }
                }
                if neighbors.reduce(0, +) > 4 {
                    grid[i][j] = 1
                } else {
                    grid[i][j] = Int.random(in: 0...1)
                }
            }
        }
    }
}

simulate()