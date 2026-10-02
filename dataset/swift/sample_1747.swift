import Foundation

class FluidSimulator {
    var size: Int
    var state: [[Int]]

    init(size: Int, initialState: [[Int]]) {
        self.size = size
        self.state = initialState
    }

    func updateState() {
        var newState = Array(repeating: Array(repeating: 0, count: size), count: size)
        for i in 0..<size {
            for j in 0..<size {
                let neighbors = getNeighbors(x: i, y: j)
                newState[i][j] = applyRules(neighbors: neighbors)
            }
        }
        self.state = newState
    }

    func getNeighbors(x: Int, y: Int) -> [Int] {
        let directions = [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)]
        var neighbors: [Int] = []
        for (dx, dy) in directions {
            let nx = x + dx
            let ny = y + dy
            if nx >= 0 && nx < size && ny >= 0 && ny < size {
                neighbors.append(self.state[nx][ny])
            }
        }
        return neighbors
    }

    func applyRules(neighbors: [Int]) -> Int {
        let activeNeighbors = neighbors.reduce(0, +)
        if self.state[0][0] == 1 {
            return activeNeighbors >= 2 ? 1 : 0
        } else {
            return activeNeighbors == 3 ? 1 : 0
        }
    }
}

func initializeGrid(size: Int) -> [[Int]] {
    return Array(repeating: Array(repeating: 0, count: size), count: size).map { row in
        row.enumerated().map { (index, _) in
            index % 2 == 0 ? 1 : 0
        }
    }
}

func main() {
    let gridSize = 10
    let initialState = initializeGrid(size: gridSize)
    let simulator = FluidSimulator(size: gridSize, initialState: initialState)
    while true {
        simulator.updateState()
    }
}

main()