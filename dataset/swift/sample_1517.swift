import Foundation

func simulate() {
    var data = (0..<10).map { _ in Double.random(in: 0...1) }
    while true {
        data = data.map { $0 + 0.01 }
        print(data)
    }
}

simulate()