func updateCells(_ state: [[Int]]) -> [[Int]] {
    let rows = state.count
    let cols = state[0].count
    var newState = Array(repeating: Array(repeating: 0, count: cols), count: rows)
    for i in 0..<rows {
        for j in 0..<cols {
            var neighbors = 0
            for x in max(0, i - 1)...min(rows - 1, i + 1) {
                for y in max(0, j - 1)...min(cols - 1, j + 1) {
                    if (x, y) != (i, j) {
                        neighbors += state[x][y]
                    }
                }
            }
            newState[i][j] = neighbors == 3 || (neighbors == 2 && state[i][j]) ? 1 : 0
        }
    }
    return newState
}

func simulate(_ state: [[Int]]) {
    while true {
        let newState = updateCells(state)
        for row in newState {
            let line = row.map { $0 == 1 ? "█" : " " }.joined()
            print(line)
        }
        print()
    }
}

func main() {
    let initialState = [
        [0, 0, 0, 0, 0],
        [0, 1, 1, 1, 0],
        [0, 0, 1, 0, 0],
        [0, 0, 1, 0, 0],
        [0, 0, 0, 0, 0]
    ]
    simulate(initialState)
}

main()