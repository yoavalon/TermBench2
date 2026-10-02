class CellularAutomata {
    var grid: [[Int]]
    var rule: Int
    var size: Int

    init(size: Int, rule: Int) {
        self.grid = Array(repeating: Array(repeating: 0, count: size), count: size)
        self.rule = rule
        self.size = size
    }

    func set_initial_state(x: Int, y: Int) {
        self.grid[x][y] = 1
    }

    func get_neighbors(x: Int, y: Int) -> Int {
        var count = 0
        for i in -1...1 {
            for j in -1...1 {
                if i == 0 && j == 0 {
                    continue
                }
                let nx = (x + i + size) % size
                let ny = (y + j + size) % size
                count += self.grid[nx][ny]
            }
        }
        return count
    }

    func update() {
        var new_grid = Array(repeating: Array(repeating: 0, count: size), count: size)
        for i in 0..<size {
            for j in 0..<size {
                let n = self.get_neighbors(x: i, y: j)
                new_grid[i][j] = self.apply_rule(state: self.grid[i][j], neighbors: n)
            }
        }
        self.grid = new_grid
    }

    func apply_rule(state: Int, neighbors: Int) -> Int {
        if state == 0 && neighbors == rule {
            return 1
        }
        return 0
    }
}

func main() {
    let ca = CellularAutomata(size: 10, rule: 3)
    ca.set_initial_state(x: 5, y: 5)
    while true {
        ca.update()
    }
}

main()