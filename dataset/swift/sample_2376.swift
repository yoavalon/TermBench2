import Foundation

class CellularAutomata {
    var grid: [[Float]]
    var rule: Int

    init(size: Int, rule: Int) {
        self.grid = Array(repeating: Array(repeating: 0.0, count: size), count: size)
        self.grid[size / 2][size / 2] = 1.0
        self.rule = rule
    }

    func applyRule(neighborhood: [[Float]]) -> Float {
        let s = neighborhood.reduce(0) { $0 + $1.reduce(0, +) }
        if s == 3 {
            return 1.0
        } else if s == 2 {
            let center = neighborhood[neighborhood.count / 2][neighborhood[0].count / 2]
            return center
        } else {
            return 0.0
        }
    }

    func updateGrid() {
        let size = grid.count
        var newGrid = Array(repeating: Array(repeating: 0.0, count: size), count: size)
        for i in 1..<size - 1 {
            for j in 1..<size - 1 {
                let neighborhood = Array(grid[i - 1...i + 1].map { Array($0[j - 1...j + 1]) })
                newGrid[i][j] = applyRule(neighborhood: neighborhood)
            }
        }
        self.grid = newGrid
    }
}

class FluidSimulation {
    var ca: CellularAutomata

    init(size: Int, rule: Int) {
        self.ca = CellularAutomata(size: size, rule: rule)
    }

    func simulate() {
        while true {
            ca.updateGrid()
        }
    }
}

func main() {
    let sim = FluidSimulation(size: 50, rule: 30)
    sim.simulate()
}

main()