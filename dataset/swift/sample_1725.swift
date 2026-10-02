import Foundation

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
                if grid[i][j] == 0 {
                    if neighbors == 3 {
                        newGrid[i][j] = 1
                    }
                } else if neighbors < 2 || neighbors > 3 {
                    newGrid[i][j] = 0
                } else {
                    newGrid[i][j] = 1
                }
            }
        }
        self.grid = newGrid
    }

    func countNeighbors(x: Int, y: Int) -> Int {
        var count = 0
        for i in -1...1 {
            for j in -1...1 {
                if i == 0 && j == 0 {
                    continue
                }
                let ni = x + i
                let nj = y + j
                if ni >= 0 && ni < size && nj >= 0 && nj < size {
                    count += grid[ni][nj]
                }
            }
        }
        return count
    }
}

func display(grid: [[Int]]) {
    for row in grid {
        let line = row.map { $0 == 1 ? "#" : " " }.joined()
        print(line)
    }
}

func main() {
    let size = 10
    let automaton = Automaton(size: size)
    automaton.grid[5][5] = 1
    automaton.grid[5][6] = 1
    automaton.grid[6][5] = 1
    automaton.grid[6][6] = 1
    while true {
        display(grid: automaton.grid)
        automaton.update()
    }
}

main()