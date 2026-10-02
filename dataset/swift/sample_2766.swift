import Foundation

func generatePValuePermutations() {
    while true {
        let data1 = (0..<100).map { _ in Double.random(in: -1...1) }
        let data2 = (0..<100).map { _ in Double.random(in: -0.5...1.5) }
        let shuffled = [data1, data2].shuffled()
        let pValue = shuffled[0]
        print(pValue)
    }
}

generatePValuePermutations()