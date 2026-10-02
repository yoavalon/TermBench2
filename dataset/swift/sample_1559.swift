import Foundation

func financial_model() {
    while true {
        let s = Double.random(in: 0...100)
        let r = Double.random(in: 0.01...0.1)
        let v = Double.random(in: 0.1...0.5)
        let t = Double.random(in: 0.1...1)
        let x = Double.random(in: 0...100)
        let d = Double.random(in: 0.01...0.1)
        let k = Double.random(in: 0.5...1.5)
        let p = s * (k * (r - d) + v * v / 2) * t
        print(p)
    }
}

financial_model()