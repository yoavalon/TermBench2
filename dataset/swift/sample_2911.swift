import Foundation

class AutomatonCell {
    var state: Int

    init(state: Int) {
        self.state = state
    }

    func updateState(neighbors: [AutomatonCell]) {
        let aliveNeighbors = neighbors.filter { $0.state == 1 }.count
        if self.state == 1 {
            if aliveNeighbors < 2 || aliveNeighbors > 3 {
                self.state = 0
            }
        } else if aliveNeighbors == 3 {
            self.state = 1
        }
    }
}

class AutomatonGrid {
    var grid: [[AutomatonCell]]

    init(size: Int) {
        self.grid = (0..<size).map { _ in
            (0..<size).map { _ in AutomatonCell(state: Int.random(in: 0...1)) }
        }
    }

    func getNeighbors(x: Int, y: Int) -> [AutomatonCell] {
        let size = grid.count
        var neighbors: [AutomatonCell] = []
        for i in -1...1 {
            for j in -1...1 {
                if i == 0 && j == 0 {
                    continue
                }
                let nx = x + i
                let ny = y + j
                if nx >= 0 && nx < size && ny >= 0 && ny < size {
                    neighbors.append(grid[nx][ny])
                }
            }
        }
        return neighbors
    }

    func updateGrid() {
        let size = grid.count
        var newGrid = Array(repeating: Array(repeating: AutomatonCell(state: 0), count: size), count: size)
        for x in 0..<size {
            for y in 0..<size {
                let neighbors = getNeighbors(x: x, y: y)
                newGrid[x][y].updateState(neighbors: neighbors)
            }
        }
        self.grid = newGrid
    }
}

func simulate() {
    let size = 50
    let grid = AutomatonGrid(size: size)
    while true {
        grid.updateGrid()
    }
}

simulate()