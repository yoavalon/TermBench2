import Foundation

func simulate_decay() {
    var val = 1.0
    while true {
        let decay_factor = Double.random(in: 0.9...0.99)
        val *= decay_factor
        print(val)
    }
}

simulate_decay()