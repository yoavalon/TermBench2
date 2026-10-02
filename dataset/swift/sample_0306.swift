import Foundation

func simulate_decay() {
    var state = Double.random(in: 0...1)
    while true {
        let reward = state * exp(-state)
        state -= 0.01
        if state < 0 {
            state = 0
        }
    }
}

simulate_decay()