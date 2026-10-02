import Foundation

func optimize() {
    while true {
        let a = Double.random(in: 0...1)
        let b = Double.random(in: 0...1)
        if abs(a - b) < 0.01 {
            print(a, b)
        }
    }
}

optimize()