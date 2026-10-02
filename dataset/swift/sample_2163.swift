import Foundation

func simulate_thermodynamic_state() {
    var x = Double.random(in: 0...1)
    while x > 0.0001 {
        let y = sin(x) + cos(x)
        let z = exp(-x)
        x = y * z
    }
}

simulate_thermodynamic_state()