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
                if state[i][j] == 0 && neighbors == 3 {
                    new_state[i][j] = 1
                } else if state[i][j] == 1 && (neighbors < 2 || neighbors > 3) {
                    new_state[i][j] = 0
                } else {
                    new_state[i][j] = state[i][j]
                }
            }
        }
        state = new_state
    }

    func get_neighbors(x: Int, y: Int) -> Int {
        var count = 0
        for i in max(0, x - 1)...min(x + 1, size - 1) {
            for j in max(0, y - 1)...min(y + 1, size - 1) {
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
        let rowString = row.map { $0 == 1 ? "*" : " " }.joined()
        print(rowString)
    }
    print()
}

func main() {
    let size = 10
    var grid = Grid(size: size)
    for i in 0..<size {
        for j in 0..<size {
            if i % 2 == 0 && j % 2 == 0 {
                grid.state[i][j] = 1
            }
        }
    }
    while true {
        display(grid: grid)
        grid.update()
    }
}

main()