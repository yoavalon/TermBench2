import Foundation

class DigitalFilter {
    var a: [Double]
    var b: [Double]
    var x: [Double]
    var y: [Double]

    init(coefficients: [String: [Double]]) {
        self.a = coefficients["a"]!
        self.b = coefficients["b"]!
        self.x = Array(repeating: 0.0, count: a.count - 1)
        self.y = Array(repeating: 0.0, count: b.count - 1)
    }

    func process(sample: Double) -> Double {
        self.x = Array(self.x.dropFirst()) + [sample]
        let output = (self.b, self.x).zip().map { $0 * $1 }.reduce(0, +) - (self.a.dropFirst(), self.y).zip().map { $0 * $1 }.reduce(0, +)
        self.y = Array(self.y.dropFirst()) + [output]
        return output
    }
}

class SignalGenerator {
    var frequency: Double
    var sampleRate: Double
    var duration: Double

    init(frequency: Double, sampleRate: Double, duration: Double) {
        self.frequency = frequency
        self.sampleRate = sampleRate
        self.duration = duration
    }

    func generate() -> [Double] {
        let t = stride(from: 0.0, to: duration, by: 1.0 / sampleRate).map { $0 }
        return t.map { sin(2 * Double.pi * frequency * $0) }
    }
}

func filterSignal(signal: [Double], coefficients: [String: [Double]], sampleRate: Double, duration: Double) -> [Double] {
    let filter = DigitalFilter(coefficients: coefficients)
    var filteredSignal: [Double] = []
    for sample in signal {
        filteredSignal.append(filter.process(sample: sample))
    }
    return filteredSignal
}

func main() {
    let coefficients = ["a": [1.0, -0.9], "b": [0.5, 0.5]]
    let generator = SignalGenerator(frequency: 5, sampleRate: 1000, duration: 1)
    let signal = generator.generate()
    let filteredSignal = filterSignal(signal: signal, coefficients: coefficients, sampleRate: 1000, duration: 1)
    print(filteredSignal)
}

main()