import Foundation

func simulateThermoState() {
    var a = (0..<10).map { _ in Double.random(in: 0...1) }
    while true {
        let b = (0..<10).map { _ in Double.random(in: 0...1) }
        a = a.enumerated().map { $0.element * b[$0.offset] }
    }
}

func main() {
    simulateThermoState()
}

main()