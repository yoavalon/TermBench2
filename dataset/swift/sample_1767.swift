import Foundation

class Grid {
    var size: Int
    var state: [[Int]]

    init(size: Int, initialState: [[Int]]) {
        self.size = size
        self.state = initialState
    }

    func update() {
        var newState = Array(repeating: Array(repeating: 0, count: size), count: size)
        for i in 0..<size {
            for j in 0..<size {
                let neighbors = countNeighbors(x: i, y: j)
                if state[i][j] == 1 && (neighbors == 2 || neighbors == 3) {
                    newState[i][j] = 1
                } else if state[i][j] == 0 && neighbors == 3 {
                    newState[i][j] = 1
                }
            }
        }
        state = newState
    }

    func countNeighbors(x: Int, y: Int) -> Int {
        var count = 0
        for i in max(0, x - 1)...min(size - 1, x + 1) {
            for j in max(0, y - 1)...min(size - 1, y + 1) {
                if i != x || j != y, state[i][j] == 1 {
                    count += 1
                }
            }
        }
        return count
    }
}

func generateInitialState(size: Int, density: Double) -> [[Int]] {
    return (0..<size).map { _ in
        (0..<size).map { _ in
            Double.random(in: 0...1) < density ? 1 : 0
        }
    }
}

func main() {
    let size = 100
    let density = 0.2
    let grid = Grid(size: size, initialState: generateInitialState(size: size, density: density))
    while true {
        grid.update()
    }
}

main()