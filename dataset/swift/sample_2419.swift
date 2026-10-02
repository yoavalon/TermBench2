func cellularAutomata(_ grid: [[Int]], steps: Int) -> [[Int]] {
    var currentGrid = grid
    for _ in 0..<steps {
        var newGrid = Array(repeating: Array(repeating: 0, count: currentGrid[0].count), count: currentGrid.count)
        for i in 0..<currentGrid.count {
            for j in 0..<currentGrid[0].count {
                let neighbors = [(i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1)].compactMap { x, y in
                    guard x >= 0, x < currentGrid.count, y >= 0, y < currentGrid[0].count else { return nil }
                    return currentGrid[x][y]
                }.reduce(0, +)
                newGrid[i][j] = (neighbors == 2) || (neighbors == 3 && currentGrid[i][j] == 1) ? 1 : 0
            }
        }
        currentGrid = newGrid
    }
    return currentGrid
}

let initialGrid = [[0, 1, 0], [0, 1, 0], [0, 1, 0]]
let steps = 5
let result = cellularAutomata(initialGrid, steps: steps)
print(result)