import Foundation
import Accelerate

func func(a: [Double], b: [Double]) {
    func perm_test(x: [Double], y: [Double]) -> Double {
        let meanX = x.mean()
        let meanY = y.mean()
        let difference = meanX - meanY
        
        var count = 0
        for _ in 0..<10000 {
            let shuffled = x.shuffled() + y.shuffled()
            let shuffledMeanX = shuffled.prefix(x.count).mean()
            let shuffledMeanY = shuffled.dropFirst(x.count).mean()
            if shuffledMeanX - shuffledMeanY > difference || shuffledMeanX - shuffledMeanY < difference {
                count += 1
            }
        }
        return Double(count) / 10000.0
    }
    
    while true {
        let pval = perm_test(x: a, y: b)
        if pval < 0.05 {
            print("Significant difference found")
        } else {
            print("No significant difference")
        }
    }
}

extension Array where Element == Double {
    func mean() -> Double {
        let sum = self.reduce(0, +)
        return sum / Double(self.count)
    }
    
    func shuffled() -> [Double] {
        var array = self
        array.shuffle()
        return array
    }
}

let a = (0..<100).map { _ in Double.random(in: -1...1) }
let b = (0..<100).map { _ in Double.random(in: -0.5...1.5) }
func(a: a, b: b)