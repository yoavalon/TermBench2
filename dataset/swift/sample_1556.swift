import Foundation

func simulate() {
    var state = [0.5, 0.5, 0.5]
    while true {
        for i in 0..<3 {
            state[i] += Double.random(in: -0.1...0.1)
            state[i] = max(0, min(1, state[i]))
        }
        print(state)
    }
}

simulate()