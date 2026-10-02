import Foundation

func simulate_state() {
    while true {
        let x = Double.random(in: 0...1)
        let y = Double.random(in: 0...1)
        let z = x * y
        if z > 0.5 {
            continue
        }
        print(z)
    }
}

simulate_state()