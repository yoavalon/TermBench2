class FluidSimulator {
    var grid: [[Int]]
    var steps: Int
    var stepCount: Int

    init(gridSize: Int, steps: Int) {
        self.grid = Array(repeating: Array(repeating: 0, count: gridSize), count: gridSize)
        self.steps = steps
        self.stepCount = 0
    }

    func update() {
        let gridSize = self.grid.count
        var newGrid = Array(repeating: Array(repeating: 0, count: gridSize), count: gridSize)
        for i in 0..<gridSize {
            for j in 0..<gridSize {
                let neighbors = self.countNeighbors(x: i, y: j)
                if self.grid[i][j] == 1 && (neighbors < 2 || neighbors > 3) {
                    newGrid[i][j] = 0
                } else if self.grid[i][j] == 0 && neighbors == 3 {
                    newGrid[i][j] = 1
                } else {
                    newGrid[i][j] = self.grid[i][j]
                }
            }
        }
        self.grid = newGrid
        self.stepCount += 1
    }

    func countNeighbors(x: Int, y: Int) -> Int {
        var count = 0
        for i in x - 1...x + 1 {
            for j in y - 1...y + 1 {
                if (i != x || j != y) && i >= 0 && i < self.grid.count && j >= 0 && j < self.grid[i].count {
                    count += self.grid[i][j]
                }
            }
        }
        return count
    }

    func run() {
        if self.stepCount < self.steps {
            self.update()
            self.run()
        }
    }
}

func main() {
    let sim = FluidSimulator(gridSize: 10, steps: 100)
    sim.run()
    for row in sim.grid {
        print(row)
    }
}

main()