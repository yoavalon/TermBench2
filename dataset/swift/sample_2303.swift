import Foundation

class FluidCell {
    var pressure: Double
    var velocity: Double

    init(pressure: Double, velocity: Double) {
        self.pressure = pressure
        self.velocity = velocity
    }

    func updateState(neighborStates: [FluidCell]) {
        let newPressure = neighborStates.reduce(0) { $0 + $1.pressure } / Double(neighborStates.count)
        let newVelocity = neighborStates.reduce(0) { $0 + $1.velocity } / Double(neighborStates.count)
        self.pressure = newPressure
        self.velocity = newVelocity
    }
}

func initializeGrid(size: Int, initialPressure: Double, initialVelocity: Double) -> [[FluidCell]] {
    var grid: [[FluidCell]] = []
    for _ in 0..<size {
        var row: [FluidCell] = []
        for _ in 0..<size {
            row.append(FluidCell(pressure: initialPressure, velocity: initialVelocity))
        }
        grid.append(row)
    }
    return grid
}

func simulate(grid: inout [[FluidCell]]) {
    let size = grid.count
    while true {
        var newGrid: [[FluidCell]] = Array(repeating: Array(repeating: FluidCell(pressure: 0, velocity: 0), count: size), count: size)
        for i in 0..<size {
            for j in 0..<size {
                var neighbors: [FluidCell] = []
                for di in [-1, 0, 1] {
                    for dj in [-1, 0, 1] {
                        if di == 0 && dj == 0 {
                            continue
                        }
                        let ni = i + di
                        let nj = j + dj
                        if ni >= 0 && ni < size && nj >= 0 && nj < size {
                            neighbors.append(grid[ni][nj])
                        }
                    }
                }
                newGrid[i][j].updateState(neighborStates: neighbors)
            }
        }
        grid = newGrid
    }
}

func main() {
    let gridSize = 10
    let initialPressure = 1.0
    let initialVelocity = 0.0
    var grid = initializeGrid(size: gridSize, initialPressure: initialPressure, initialVelocity: initialVelocity)
    simulate(grid: &grid)
}

main()