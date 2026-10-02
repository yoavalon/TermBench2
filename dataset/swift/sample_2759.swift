import Foundation

func simulate() {
    let size = (20, 20)
    var state = (0..<size.0).map { _ in (0..<size.1).map { _ in Int.random(in: 0...1) } }
    
    func update(_ state: [[Int]]) -> [[Int]] {
        let rows = state.count
        let cols = state[0].count
        var newState = state.map { $0.map { $0 } }
        
        for i in 0..<rows {
            for j in 0..<cols {
                let neighbors = [
                    (i-1, j), (i+1, j), (i, j-1), (i, j+1)
                ].filter { $0.0 >= 0 && $0.0 < rows && $0.1 >= 0 && $0.1 < cols }
                .map { state[$0.0][$0.1] }
                .reduce(0, +)
                
                if state[i][j] == 1 && neighbors < 2 {
                    newState[i][j] = 0
                } else if state[i][j] == 1 && neighbors > 3 {
                    newState[i][j] = 0
                } else if state[i][j] == 0 && neighbors == 3 {
                    newState[i][j] = 1
                }
            }
        }
        return newState
    }
    
    while true {
        state = update(state)
    }
}

simulate()