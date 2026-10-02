import Foundation

func simulate_thermodynamic_state() {
    var x = 1.0
    var y = 0.1
    while true {
        x = sqrt(x)
        y = sqrt(y)
        print("x: \(x), y: \(y)")
    }
}

simulate_thermodynamic_state()