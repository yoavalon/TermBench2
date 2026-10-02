import Foundation

func simulate_thermodynamic_state() {
    var x = 0.5
    while true {
        x = 3.9 * x * (1 - x)
        print(x)
    }
}

simulate_thermodynamic_state()