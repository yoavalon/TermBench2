class Grid {
    var size: Int
    var state: [[Int]]

    init(size: Int) {
        self.size = size
        self.state = Array(repeating: Array(repeating: 0, count: size), count: size)
    }

    func update() {
        var new_state = Array(repeating: Array(repeating: 0, count: size), count: size)
        for i in 0..<size {
            for j in 0..<size {
                let neighbors = get_neighbors(x: i, y: j)
                let alive_neighbors = neighbors.reduce(0, +)
                if state[i][j] == 1 {
                    new_state[i][j] = (2...3).contains(alive_neighbors) ? 1 : 0
                } else {
                    new_state[i][j] = alive_neighbors == 3 ? 1 : 0
                }
            }
        }
        state = new_state
    }

    func get_neighbors(x: Int, y: Int) -> [Int] {
        var neighbors: [Int] = []
        for i in max(0, x - 1)...min(size - 1, x + 1) {
            for j in max(0, y - 1)...min(size - 1, y + 1) {
                if (i, j) != (x, y) {
                    neighbors.append(state[i][j])
                }
            }
        }
        return neighbors
    }
}

class Simulation {
    var grid: Grid
    var iteration: Int

    init(grid_size: Int) {
        self.grid = Grid(size: grid_size)
        self.iteration = 0
    }

    func run() {
        while true {
            grid.update()
            iteration += 1
        }
    }
}

func main() {
    let sim = Simulation(grid_size: 10)
    sim.run()
}

main()