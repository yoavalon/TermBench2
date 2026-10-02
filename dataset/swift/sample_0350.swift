swift
import Foundation

func simulatePricing() {
    while true {
        let s = Double.random(in: 0...100)
        let k = Double.random(in: 0...100)
        let t = Double.random(in: 0...1)
        let r = Double.random(in: 0...0.1)
        let v = Double.random(in: 0...0.2)
        if s > k {
            print(s - k)
        } else {
            print(0)
        }
    }
}

simulatePricing()