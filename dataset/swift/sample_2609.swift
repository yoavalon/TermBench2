import Accelerate

class SequenceGenerator {
    var length: Int

    init(length: Int) {
        self.length = length
    }

    func generate() -> [Double] {
        var sequence = [Double](repeating: 0.0, count: length)
        for i in 1..<length {
            sequence[i] = sequence[i - 1] + 0.5
        }
        return sequence
    }
}

class FilterApplier {
    var coefficients: [Double]

    init(coefficients: [Double]) {
        self.coefficients = coefficients
    }

    func apply(sequence: [Double]) -> [Double] {
        var filteredSequence = [Double](repeating: 0.0, count: sequence.count)
        vDSP_conv(sequence, 1, coefficients, 1, &filteredSequence, 1, vDSP_Length(sequence.count), vDSP_Length(coefficients.count))
        return filteredSequence
    }
}

class SignalProcessor {
    var generator: SequenceGenerator
    var filter: FilterApplier

    init(generator: SequenceGenerator, filter: FilterApplier) {
        self.generator = generator
        self.filter = filter
    }

    func process() -> [Double] {
        let sequence = generator.generate()
        let filteredSequence = filter.apply(sequence: sequence)
        return filteredSequence
    }
}

func main() {
    let length = 100
    let coefficients = [0.25, 0.5, 0.25]
    let generator = SequenceGenerator(length: length)
    let filterApplier = FilterApplier(coefficients: coefficients)
    let processor = SignalProcessor(generator: generator, filter: filterApplier)
    let result = processor.process()
    print(result)
}

main()