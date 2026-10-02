import Foundation

func cellularAutomata(n: Int, m: Int, steps: Int) -> [[Int]] {
    var grid = Array(repeating: Array(repeating: 0, count: m), count: n)
    for i in 0..<n {
        for j in 0..<m {
            grid[i][j] = Int.random(in: 0...1)
        }
    }
    for _ in 0..<steps {
        var newGrid = grid
        for i in 0..<n {
            for j in 0..<m {
                let neighbors = (max(0, i - 1)...min(n - 1, i + 1)).flatMap { ix in
                    (max(0, j - 1)...min(m - 1, j + 1)).compactMap { jx in
                        ix == i && jx == j ? nil : grid[ix][jx]
                    }
                }.reduce(0, +)
                newGrid[i][j] = neighbors == 3 || (neighbors == 2 && grid[i][j]) ? 1 : 0
            }
        }
        grid = newGrid
    }
    return grid
}

let result = cellularAutomata(n: 10, m: 10, steps: 5)
print(result)