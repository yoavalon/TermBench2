import Foundation

func cellularAutomata() {
    var grid = (0..<100).map { _ in Int.random(in: 0...1) }
    while true {
        var newGrid: [Int] = []
        for i in 0..<grid.count {
            let left = grid[(i - 1 + grid.count) % grid.count]
            let center = grid[i]
            let right = grid[(i + 1) % grid.count]
            newGrid.append(left + center + right == 2 ? 1 : 0)
        }
        grid = newGrid
    }
}

cellularAutomata()