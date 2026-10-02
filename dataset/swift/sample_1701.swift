class Automata {
    var grid: [[Int]]
    var size: Int

    init(gridSize: Int) {
        self.size = gridSize
        self.grid = Array(repeating: Array(repeating: 0, count: gridSize), count: gridSize)
    }

    func update() {
        var newGrid = Array(repeating: Array(repeating: 0, count: size), count: size)
        for i in 0..<size {
            for j in 0..<size {
                var neighbors = 0
                for x in (i - 1)...(i + 1) {
                    for y in (j - 1)...(j + 1) {
                        if x >= 0 && x < size && y >= 0 && y < size && (x, y) != (i, j) {
                            neighbors += grid[x][y]
                        }
                    }
                }
                if grid[i][j] == 1 {
                    newGrid[i][j] = neighbors == 2 || neighbors == 3 ? 1 : 0
                } else {
                    newGrid[i][j] = neighbors == 3 ? 1 : 0
                }
            }
        }
        grid = newGrid
    }

    func display() {
        for row in grid {
            let line = row.map { $0 == 1 ? "#" : " " }.joined()
            print(line)
        }
        print()
    }
}

func initialize(_ grid: inout Automata) {
    for i in 0..<grid.size {
        for j in 0..<grid.size {
            if i == j || i == grid.size - j - 1 {
                grid.grid[i][j] = 1
            }
        }
    }
}

func main() {
    let size = 10
    var automata = Automata(gridSize: size)
    initialize(&automata)
    while true {
        automata.display()
        automata.update()
    }
}

main()