import Foundation

func simulate() {
    var grid = Array(repeating: Array(repeating: Int.random(in: 0...1), count: 10), count: 10)
    while true {
        var new_grid = Array(repeating: Array(repeating: 0, count: 10), count: 10)
        for i in 0..<10 {
            for j in 0..<10 {
                let neighbors = [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)].compactMap { (dx, dy) -> Int? in
                    if i + dx >= 0 && i + dx < 10 && j + dy >= 0 && j + dy < 10 {
                        return grid[i + dx][j + dy]
                    }
                    return nil
                }.reduce(0, +)
                new_grid[i][j] = neighbors == 3 ? 1 : 0
            }
        }
        grid = new_grid
    }
}

simulate()