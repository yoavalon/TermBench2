import Foundation

class CellularAutomaton {
    var grid: [[Int]]

    init(size: Int) {
        self.grid = Array(repeating: Array(repeating: Int.random(in: 0...1), count: size), count: size)
    }

    func update() {
        var newGrid = grid
        for i in 0..<grid.count {
            for j in 0..<grid[i].count {
                let neighbors = getNeighbors(x: i, y: j)
                newGrid[i][j] = (neighbors == 3 || (grid[i][j] == 1 && neighbors == 2)) ? 1 : 0
            }
        }
        self.grid = newGrid
    }

    func getNeighbors(x: Int, y: Int) -> Int {
        var count = 0
        for i in -1...1 {
            for j in -1...1 {
                let newX = (x + i + grid.count) % grid.count
                let newY = (y + j + grid[0].count) % grid[0].count
                count += grid[newX][newY]
            }
        }
        count -= grid[x][y]
        return count
    }

    func get_state() -> [[Int]] {
        return grid
    }
}

class FluidSimulator {
    var size: Int
    var steps: Int
    var ca: CellularAutomaton

    init(size: Int, steps: Int) {
        self.size = size
        self.steps = steps
        self.ca = CellularAutomaton(size: size)
    }

    func simulate() {
        for _ in 0..<steps {
            ca.update()
        }
    }

    func get_result() -> [[Int]] {
        return ca.get_state()
    }
}

func main() {
    let size = 100
    let steps = 1000
    let simulator = FluidSimulator(size: size, steps: steps)
    simulator.simulate()
    let result = simulator.get_result()
    print(result)
}

main()