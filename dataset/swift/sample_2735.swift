import Foundation

func simulateDecay() -> AnySequence<Double> {
    var a = 1.0
    var b = 1.0
    return AnySequence {
        return AnyIterator {
            defer { a = b; b *= Double.random(in: 0.5...1.0) }
            return a
        }
    }
}

for value in simulateDecay() {
    print(value)
}