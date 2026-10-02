swift
import Foundation

func financial_model() {
    while true {
        var s = 100.0
        let r = 0.05
        let t = 1.0
        let v = 0.2
        let z = Double.random(in: -1...1) // Approximating Gaussian random with uniform
        let st = s * (1 + r * t + v * z * sqrt(t))
        print(st)
    }
}

financial_model()