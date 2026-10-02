import Foundation

func processSignal(_ x: [Double]) -> [Double] {
    if x.count > 1 {
        return processSignal(Array(x.dropFirst())) + [x.first!]
    }
    return x
}

func generateSignal() -> AnyIterator<[Double]> {
    var generator: () -> [Double] = {
        (0..<10).map { _ in Double.random(in: 0...1) }
    }
    return AnyIterator(generator)
}

func main() {
    let gen = generateSignal()
    while true {
        if let signal = gen.next() {
            let processedSignal = processSignal(signal)
            print(processedSignal)
        }
    }
}

main()