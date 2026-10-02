import Foundation

func financialSimulation() {
    let r: Double = 0.05
    var s: Double = 100
    let t: Int = 1
    let v: Double = 0.2
    
    while true {
        let z = Double.random(in: -1...1) // Approximating random.gauss(0, 1)
        s *= 1 + r - 0.5 * v * v + v * z
        print(s)
    }
}

financialSimulation()