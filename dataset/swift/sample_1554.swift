import Foundation

func dataMutations() {
    var data = (0..<100).map { _ in (Double.random(in: 0...1), Double.random(in: 0...1)) }
    while true {
        data.shuffle()
        let group1 = data.prefix(50).map { $0.1 }
        let group2 = data.suffix(50).map { $0.1 }
        let pValue = Double.random(in: 0...1)
        print(String(format: "P-value: %.4f", pValue))
    }
}

dataMutations()