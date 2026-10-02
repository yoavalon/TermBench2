import Foundation

func updateGrid(_ grid: [[Int]]) -> [[Int]] {
    let size = grid.count
    var newGrid = Array(repeating: Array(repeating: 0, count: size), count: size)
    for x in 0..<size {
        for y in 0..<size {
            var neighbors = 0
            for dx in -1...1 {
                for dy in -1...1 {
                    if (dx, dy) != (0, 0) {
                        neighbors += grid[(x + dx + size) % size][(y + dy + size) % size]
                    }
                }
            }
            newGrid[x][y] = (2...3).contains(neighbors) ? 1 : 0
        }
    }
    return newGrid
}

func simulate(_ grid: [[Int]]) {
    var currentGrid = grid
    if currentGrid.isEmpty {
        currentGrid = Array(repeating: Array(repeating: Int.random(in: 0...1), count: 10), count: 10)
    }
    for row in currentGrid {
        print(row.map { String($0) }.joined())
    }
    simulate(updateGrid(currentGrid))
}

simulate([])