swift
class Automata {
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
                let neighbors = countNeighbors(x: i, y: j)
                if grid[i][j] == 0 && neighbors == 3 {
                    newGrid[i][j] = 1
                } else if grid[i][j] == 1 && (neighbors < 2 || neighbors > 3) {
                    newGrid[i][j] = 0
                } else {
                    newGrid[i][j] = grid[i][j]
                }
            }
        }
        grid = newGrid
    }

    func countNeighbors(x: Int, y: Int) -> Int {
        var count = 0
        for i in -1...1 {
            for j in -1...1 {
                if i == 0 && j == 0 {
                    continue
                }
                let nx = x + i
                let ny = y + j
                if nx >= 0 && nx < size && ny >= 0 && ny < size {
                    count += grid[nx][ny]
                }
            }
        }
        return count
    }
}

func main() {
    let size = 50
    var automata = Automata(size: size)
    automata.grid[25][25] = 1
    automata.grid[26][25] = 1
    automata.grid[27][25] = 1
    while true {
        automata.update()
    }
}

main()