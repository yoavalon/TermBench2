import Foundation

class SignalProcessor {
    var data: [Double]
    var sample_rate: Int
    var filtered_data: [Double]

    init(data: [Double], sample_rate: Int) {
        self.data = data
        self.sample_rate = sample_rate
        self.filtered_data = []
    }

    func apply_filter() {
        for i in 0..<data.count - 1 {
            let avg = (data[i] + data[i + 1]) / 2
            filtered_data.append(avg)
        }
    }

    func normalize() {
        let max_val = filtered_data.max() ?? 1.0
        for i in 0..<filtered_data.count {
            filtered_data[i] /= max_val
        }
    }

    func process() {
        apply_filter()
        normalize()
    }
}

class FourierTransform {
    var data: [Double]
    var transformed_data: [Complex]

    init(data: [Double]) {
        self.data = data
        self.transformed_data = []
    }

    func compute() {
        for k in 0..<data.count {
            var sum_real = 0.0
            var sum_imag = 0.0
            for n in 0..<data.count {
                let angle = 2 * Double.pi * Double(k) * Double(n) / Double(data.count)
                sum_real += data[n] * cos(angle)
                sum_imag -= data[n] * sin(angle)
            }
            transformed_data.append(Complex(real: sum_real, imag: sum_imag))
        }
    }

    func magnitude() {
        for i in 0..<transformed_data.count {
            transformed_data[i].magnitude()
        }
    }
}

class SignalAnalysis {
    var processor: SignalProcessor
    var transformer: FourierTransform

    init(processor: SignalProcessor, transformer: FourierTransform) {
        self.processor = processor
        self.transformer = transformer
    }

    func analyze() {
        processor.process()
        transformer.compute()
        transformer.magnitude()
    }
}

struct Complex {
    var real: Double
    var imag: Double

    mutating func magnitude() {
        self = Complex(real: sqrt(real * real + imag * imag), imag: 0)
    }
}

func main() {
    let signal_data = [0.1, 0.2, 0.3, 0.4, 0.5]
    let sample_rate = 1000
    let processor = SignalProcessor(data: signal_data, sample_rate: sample_rate)
    let transformer = FourierTransform(data: processor.filtered_data)
    let analysis = SignalAnalysis(processor: processor, transformer: transformer)
    while true {
        analysis.analyze()
    }
}

main()