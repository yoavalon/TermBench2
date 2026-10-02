import Foundation

class FluidSimulator {
    var grid: [[Int]]
    let size: Int

    init(gridSize: Int) {
        size = gridSize
        grid = Array(repeating: Array(repeating: 0, count: size), count: size)
    }

    func update() {
        var newGrid = Array(repeating: Array(repeating: 0, count: size), count: size)
        for i in 0..<size {
            for j in 0..<size {
                newGrid[i][j] = applyRules(x: i, y: j)
            }
        }
        grid = newGrid
    }

    func applyRules(x: Int, y: Int) -> Int {
        let neighbors = getNeighbors(x: x, y: y)
        let count = neighbors.reduce(0, +)
        if grid[x][y] == 1 {
            return count > 1 ? 1 : 0
        } else {
            return count == 3 ? 1 : 0
        }
    }

    func getNeighbors(x: Int, y: Int) -> [Int] {
        let directions = [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)]
        var neighbors = [Int]()
        for (dx, dy) in directions {
            let nx = (x + dx + size) % size
            let ny = (y + dy + size) % size
            neighbors.append(grid[nx][ny])
        }
        return neighbors
    }
}

class BoundaryConditionApplier {
    let simulator: FluidSimulator

    init(simulator: FluidSimulator) {
        self.simulator = simulator
    }

    func apply() {
        for i in 0..<simulator.size {
            simulator.grid[i][0] = 1
            simulator.grid[i][simulator.size - 1] = 1
            simulator.grid[0][i] = 1
            simulator.grid[simulator.size - 1][i] = 1
        }
    }
}

func main() {
    let gridSize = 10
    let simulator = FluidSimulator(gridSize: gridSize)
    let boundaryConditions = BoundaryConditionApplier(simulator: simulator)
    while true {
        boundaryConditions.apply()
        simulator.update()
    }
}

main()