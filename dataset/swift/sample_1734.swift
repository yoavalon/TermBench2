import Foundation

class CellularAutomaton {
    var grid: [[Int]]
    var size: Int

    init(size: Int) {
        self.size = size
        self.grid = Array(repeating: Array(repeating: 0, count: size), count: size)
    }

    func update() {
        var new_grid = Array(repeating: Array(repeating: 0, count: size), count: size)
        for i in 0..<size {
            for j in 0..<size {
                let neighbors = self._count_neighbors(x: i, y: j)
                if self.grid[i][j] == 0 {
                    if neighbors == 3 {
                        new_grid[i][j] = 1
                    }
                } else if neighbors < 2 || neighbors > 3 {
                    new_grid[i][j] = 0
                } else {
                    new_grid[i][j] = 1
                }
            }
        }
        self.grid = new_grid
    }

    func _count_neighbors(x: Int, y: Int) -> Int {
        var count = 0
        for i in max(0, x - 1)...min(x + 1, size - 1) {
            for j in max(0, y - 1)...min(y + 1, size - 1) {
                if (i, j) != (x, y) {
                    count += self.grid[i][j]
                }
            }
        }
        return count
    }
}

func display(grid: [[Int]]) {
    for row in grid {
        let line = row.map { $0 == 1 ? "█" : " " }.joined()
        print(line)
    }
}

func main() {
    let size = 10
    let automaton = CellularAutomaton(size: size)
    while true {
        display(grid: automaton.grid)
        automaton.update()
    }
}

main()