import Foundation

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
                let neighbors = self._countNeighbors(x: i, y: j)
                if self.grid[i][j] == 1 {
                    if neighbors < 2 || neighbors > 3 {
                        newGrid[i][j] = 0
                    } else {
                        newGrid[i][j] = 1
                    }
                } else if neighbors == 3 {
                    newGrid[i][j] = 1
                }
            }
        }
        self.grid = newGrid
    }

    private func _countNeighbors(x: Int, y: Int) -> Int {
        var count = 0
        for i in max(0, x - 1)...min(x + 1, size - 1) {
            for j in max(0, y - 1)...min(y + 1, size - 1) {
                if (i, j) != (x, y) && self.grid[i][j] == 1 {
                    count += 1
                }
            }
        }
        return count
    }
}

func main() {
    let size = 10
    let ca = CellularAutomata(size: size)
    for _ in 0..<100 {
        ca.update()
    }
    for row in ca.grid {
        let rowString = row.map { $0 == 1 ? "*" : " " }.joined()
        print(rowString)
    }
}

main()