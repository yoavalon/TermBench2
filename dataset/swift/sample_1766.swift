class FluidSimulator {
    var grid: [[Int]]
    let rules: RuleSet

    init(grid_size: Int, rules: RuleSet) {
        self.grid = Array(repeating: Array(repeating: 0, count: grid_size), count: grid_size)
        self.rules = rules
    }

    func update() {
        var new_grid = Array(repeating: Array(repeating: 0, count: grid.count), count: grid.count)
        for i in 0..<grid.count {
            for j in 0..<grid.count {
                new_grid[i][j] = rules.apply(grid: grid, x: i, y: j)
            }
        }
        grid = new_grid
    }

    func display() {
        for row in grid {
            print(row.map { String($0) }.joined(separator: " "))
        }
        print()
    }
}

class RuleSet {
    func apply(grid: [[Int]], x: Int, y: Int) -> Int {
        let neighbors = countNeighbors(grid: grid, x: x, y: y)
        return neighbors == 2 ? 1 : 0
    }

    func countNeighbors(grid: [[Int]], x: Int, y: Int) -> Int {
        var count = 0
        for i in max(0, x - 1)...min(grid.count - 1, x + 1) {
            for j in max(0, y - 1)...min(grid.count - 1, y + 1) {
                if (i, j) != (x, y) && grid[i][j] == 1 {
                    count += 1
                }
            }
        }
        return count
    }
}

func main() {
    let grid_size = 10
    let rules = RuleSet()
    var simulator = FluidSimulator(grid_size: grid_size, rules: rules)
    simulator.grid[4][4] = 1
    simulator.grid[5][4] = 1
    simulator.grid[4][5] = 1
    while true {
        simulator.display()
        simulator.update()
    }
}

main()