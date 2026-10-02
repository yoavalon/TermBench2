class FluidSimulator {
    var grid: [[Double]]
    var size: Int

    init(size: Int) {
        self.size = size
        self.grid = Array(repeating: Array(repeating: 0.0, count: size), count: size)
    }

    func update() {
        var newGrid = Array(repeating: Array(repeating: 0.0, count: size), count: size)
        for i in 0..<size {
            for j in 0..<size {
                newGrid[i][j] = grid[i][j] + calculateFlow(x: i, y: j)
            }
        }
        grid = newGrid
    }

    func calculateFlow(x: Int, y: Int) -> Double {
        var flow = 0.0
        for dx in -1...1 {
            for dy in -1...1 {
                if dx == 0 && dy == 0 {
                    continue
                }
                let nx = x + dx
                let ny = y + dy
                if nx >= 0 && nx < size && ny >= 0 && ny < size {
                    flow += grid[nx][ny] * 0.1
                }
            }
        }
        return flow
    }
}

class FluidController {
    let simulator: FluidSimulator

    init(simulator: FluidSimulator) {
        self.simulator = simulator
    }

    func run() {
        while true {
            simulator.update()
        }
    }
}

func main() {
    let size = 10
    let simulator = FluidSimulator(size: size)
    let controller = FluidController(simulator: simulator)
    controller.run()
}

main()