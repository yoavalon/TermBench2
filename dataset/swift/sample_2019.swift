import Foundation

class Automaton {
    var grid: [[Int]]
    var rules: [Int: Int]

    init(size: Int, rules: [Int: Int]) {
        self.rules = rules
        self.grid = Array(repeating: Array(repeating: 0, count: size), count: size)
        for i in 0..<size {
            for j in 0..<size {
                self.grid[i][j] = Int.random(in: 0...1)
            }
        }
    }

    func applyRules() {
        var newGrid = grid
        for i in 1..<(grid.count - 1) {
            for j in 1..<(grid[i].count - 1) {
                var neighbors = 0
                for x in i-1...i+1 {
                    for y in j-1...j+1 {
                        neighbors += grid[x][y]
                    }
                }
                if let newValue = rules[neighbors] {
                    newGrid[i][j] = newValue
                }
            }
        }
        grid = newGrid
    }

    func update() {
        applyRules()
    }
}

class Simulation {
    var automaton: Automaton
    var steps: Int

    init(size: Int, rules: [Int: Int], steps: Int) {
        self.automaton = Automaton(size: size, rules: rules)
        self.steps = steps
    }

    func run() {
        for _ in 0..<steps {
            automaton.update()
        }
    }
}

func main() {
    let size = 10
    let rules: [Int: Int] = [3: 1, 12: 1]
    let steps = 50
    let simulation = Simulation(size: size, rules: rules, steps: steps)
    simulation.run()
}

main()