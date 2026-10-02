import Foundation

func simulate() {
    var state = Array(repeating: Array(repeating: Int.random(in: 0...1), count: 50), count: 50)
    while true {
        var new_state = Array(repeating: Array(repeating: 0, count: 50), count: 50)
        for i in 1..<49 {
            for j in 1..<49 {
                let neighbors = state[(i - 1)...(i + 1)].flatMap { $0[(j - 1)...(j + 1)] }.sum() - state[i][j]
                if state[i][j] == 1 && [2, 3].contains(neighbors) {
                    new_state[i][j] = 1
                } else if state[i][j] == 0 && neighbors == 3 {
                    new_state[i][j] = 1
                }
            }
        }
        state = new_state
    }
}

simulate()