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
                let neighbors = count_neighbors(x: i, y: j)
                if state[i][j] == 0 {
                    if neighbors == 3 {
                        new_state[i][j] = 1
                    }
                } else if neighbors == 2 || neighbors == 3 {
                    new_state[i][j] = 1
                }
            }
        }
        state = new_state
    }

    func count_neighbors(x: Int, y: Int) -> Int {
        var count = 0
        for i in max(0, x - 1)...min(size - 1, x + 1) {
            for j in max(0, y - 1)...min(size - 1, y + 1) {
                if (i, j) != (x, y) && state[i][j] == 1 {
                    count += 1
                }
            }
        }
        return count
    }
}

func display(grid: Grid) {
    for row in grid.state {
        print(String(row.map { $0 == 1 ? "O" : "." }))
    }
    print()
}

func main() {
    let size = 50
    var grid = Grid(size: size)
    for i in 0..<size {
        for j in 0..<size {
            grid.state[i][j] = (i + j) % 2 == 0 ? 1 : 0
        }
    }
    while true {
        display(grid: grid)
        grid.update()
    }
}

main()