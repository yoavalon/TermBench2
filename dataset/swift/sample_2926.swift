class CellularAutomata {
    var grid: [[Int]]
    var size: Int

    init(size: Int) {
        self.size = size
        self.grid = Array(repeating: Array(repeating: 0, count: size), count: size)
    }

    func update() {
        var newGrid = Array(repeating: Array(repeating: 0, count: size), count: size)
        for i in 0..<size {
            for j in 0..<size {
                let state = grid[i][j]
                let neighbors = countNeighbors(x: i, y: j)
                if state == 0 && neighbors == 3 {
                    newGrid[i][j] = 1
                } else if state == 1 && (neighbors < 2 || neighbors > 3) {
                    newGrid[i][j] = 0
                } else {
                    newGrid[i][j] = state
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

class Simulation {
    var automata: CellularAutomata
    var size: Int

    init(size: Int) {
        self.automata = CellularAutomata(size: size)
        self.size = size
    }

    func run() {
        while true {
            automata.update()
        }
    }
}

func main() {
    let simulation = Simulation(size: 10)
    simulation.run()
}

main()