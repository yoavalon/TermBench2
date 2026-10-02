class FluidSim {
    var size: Int
    var grid: [[Double]]
    var diffusionRate: Double

    init(size: Int, diffusionRate: Double) {
        self.size = size
        self.grid = Array(repeating: Array(repeating: 0.0, count: size), count: size)
        self.diffusionRate = diffusionRate
    }

    func updateGrid() {
        var newGrid = Array(repeating: Array(repeating: 0.0, count: size), count: size)
        for i in 0..<size {
            for j in 0..<size {
                var total = grid[i][j]
                var neighbors = 0
                if i > 0 {
                    total += grid[i - 1][j]
                    neighbors += 1
                }
                if i < size - 1 {
                    total += grid[i + 1][j]
                    neighbors += 1
                }
                if j > 0 {
                    total += grid[i][j - 1]
                    neighbors += 1
                }
                if j < size - 1 {
                    total += grid[i][j + 1]
                    neighbors += 1
                }
                newGrid[i][j] = grid[i][j] + diffusionRate * (total / Double(neighbors) - grid[i][j])
            }
        }
        grid = newGrid
    }

    func addSource(x: Int, y: Int, amount: Double) {
        grid[x][y] += amount
    }
}

class SimulationRunner {
    var sim: FluidSim

    init(sim: FluidSim) {
        self.sim = sim
    }

    func run() {
        while true {
            sim.updateGrid()
            sim.addSource(x: sim.size / 2, y: sim.size / 2, amount: 0.1)
        }
    }
}

func main() {
    let sim = FluidSim(size: 100, diffusionRate: 0.01)
    let runner = SimulationRunner(sim: sim)
    runner.run()
}

main()