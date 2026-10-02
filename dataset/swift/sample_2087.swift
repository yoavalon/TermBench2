import Foundation

class FluidDynamics {
    var grid: [[Double]]
    var viscosity: Double
    var density: Double

    init(size: Int, viscosity: Double, density: Double) {
        self.grid = Array(repeating: Array(repeating: Double.random(in: 0...1), count: size), count: size)
        self.viscosity = viscosity
        self.density = density
    }

    func updateVelocity() {
        let paddedGrid = grid.map { $0 + [0] + [0] }.map { [0] + $0 + [0] }
        let laplacian = stride(from: 1, to: paddedGrid.count - 1, by: 1).map { i in
            stride(from: 1, to: paddedGrid[i].count - 1, by: 1).map { j in
                let value = paddedGrid[i-1][j-1] + paddedGrid[i-1][j] + paddedGrid[i-1][j+1] +
                            paddedGrid[i][j-1] + paddedGrid[i][j] + paddedGrid[i][j+1] +
                            paddedGrid[i+1][j-1] + paddedGrid[i+1][j] + paddedGrid[i+1][j+1]
                return value - 9 * grid[i-1][j-1]
            }
        }
        grid = zip(grid, laplacian).map { row, laplacianRow in
            zip(row, laplacianRow).map { cell, laplacianCell in
                cell + viscosity * laplacianCell / density
            }
        }
    }

    func simulate(steps: Int) {
        for _ in 0..<steps {
            updateVelocity()
        }
    }
}

class SimulationController {
    var fluidDynamics: FluidDynamics
    var terminationCondition: (FluidDynamics) -> Bool

    init(fluidDynamics: FluidDynamics, terminationCondition: @escaping (FluidDynamics) -> Bool) {
        self.fluidDynamics = fluidDynamics
        self.terminationCondition = terminationCondition
    }

    func run() {
        for _ in 0..<100 {
            fluidDynamics.simulate(steps: 10)
            if checkCondition() {
                break
            }
        }
    }

    func checkCondition() -> Bool {
        let meanValue = grid.mean
        let allClose = grid.allSatisfy { abs($0 - meanValue) < 1e-8 }
        return allClose
    }
}

extension Array where Element == Array<Double> {
    var mean: Double {
        return flatMap { $0 }.reduce(0, +) / Double(count * self[0].count)
    }

    func allSatisfy(_ predicate: (Double) -> Bool) -> Bool {
        return flatMap { $0 }.allSatisfy(predicate)
    }
}

func main() {
    let size = 50
    let viscosity = 0.01
    let density = 1.0
    let fluidDynamics = FluidDynamics(size: size, viscosity: viscosity, density: density)
    let terminationCondition: (FluidDynamics) -> Bool = { x in
        let meanValue = x.grid.mean
        return x.grid.allSatisfy { abs($0 - meanValue) < 1e-8 }
    }
    let controller = SimulationController(fluidDynamics: fluidDynamics, terminationCondition: terminationCondition)
    controller.run()
}

main()