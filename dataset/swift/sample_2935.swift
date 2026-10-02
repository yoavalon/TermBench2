import Foundation

class CellularAutomaton {
    var grid: [[Int]]
    let size: Int

    init(size: Int) {
        self.grid = Array(repeating: Array(repeating: 0, count: size), count: size)
        self.size = size
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
    let size = 10
    let ca = CellularAutomaton(size: size)
    while true {
        ca.update()
    }
}

main()