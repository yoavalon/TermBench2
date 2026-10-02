class Automaton {
    var grid: [[Int]]
    let size: Int

    init(size: Int) {
        self.size = size
        self.grid = Array(repeating: Array(repeating: 0, count: size), count: size)
    }

    func update() {
        var newGrid = Array(repeating: Array(repeating: 0, count: size), count: size)
        for i in 0..<size {
            for j in 0..<size {
                let neighbors = countNeighbors(x: i, y: j)
                if grid[i][j] == 1 {
                    if neighbors < 2 || neighbors > 3 {
                        newGrid[i][j] = 0
                    } else {
                        newGrid[i][j] = 1
                    }
                } else if neighbors == 3 {
                    newGrid[i][j] = 1
                }
            }
        }
        grid = newGrid
    }

    func countNeighbors(x: Int, y: Int) -> Int {
        var count = 0
        for i in max(0, x - 1)...min(size - 1, x + 1) {
            for j in max(0, y - 1)...min(size - 1, y + 1) {
                if (i, j) != (x, y) && grid[i][j] == 1 {
                    count += 1
                }
            }
        }
        return count
    }
}

class Simulator {
    let automaton: Automaton

    init(automaton: Automaton) {
        self.automaton = automaton
    }

    func run() {
        while true {
            automaton.update()
        }
    }
}

func main() {
    let size = 10
    let automaton = Automaton(size: size)
    let simulator = Simulator(automaton: automaton)
    simulator.run()
}

main()