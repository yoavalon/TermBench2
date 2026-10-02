import Foundation

class SignalProcessor {
    var data: [Double]

    init(data: [Double]) {
        self.data = data
    }

    func applyFilter(kernel: [Double]) -> [Double] {
        let result = convolve(data: data, kernel: kernel, mode: "same")
        return result
    }

    func normalize(data: [Double]) -> [Double] {
        let minVal = data.min() ?? 0
        let maxVal = data.max() ?? 1
        let normalized = data.map { (\$0 - minVal) / (maxVal - minVal) }
        return normalized
    }
}

class SequenceGenerator {
    var length: Int

    init(length: Int) {
        self.length = length
    }

    func generateSineWave(frequency: Double, amplitude: Double, phase: Double) -> [Double] {
        let t = stride(from: 0.0, to: 1.0, by: 1.0 / Double(length)).dropLast()
        let wave = t.map { amplitude * sin(2 * Double.pi * frequency * \$0 + phase) }
        return wave
    }
}

class Analysis {
    var data: [Double]

    init(processedData: [Double]) {
        self.data = processedData
    }

    func calculateFFT() -> [Double] {
        let fftResult = fft(data: data)
        return fftResult
    }

    func findPeakFrequency(fftResult: [Double]) -> Double {
        let freqs = fftFreqs(length: fftResult.count)
        let peakIdx = fftResult.enumerated().max(by: { abs(\$0.element) < abs(\$1.element) })?.offset ?? 0
        let peakFreq = freqs[peakIdx]
        return peakFreq
    }
}

func convolve(data: [Double], kernel: [Double], mode: String) -> [Double] {
    let padding = kernel.count / 2
    let paddedData = Array(repeating: 0.0, count: padding) + data + Array(repeating: 0.0, count: padding)
    var result = [Double](repeating: 0.0, count: data.count)

    for i in 0..<data.count {
        let start = i
        let end = start + kernel.count
        let slice = Array(paddedData[start..<end])
        result[i] = slice.enumerated().map { \$0.element * kernel[\$0.offset] }.reduce(0, +)
    }

    return result
}

func fft(data: [Double]) -> [Double] {
    let length = data.count
    guard length > 1 else { return data }

    let even = stride(from: 0, to: length, by: 2).map { data[\$0] }
    let odd = stride(from: 1, to: length, by: 2).map { data[\$0] }

    let evenFFT = fft(data: even)
    let oddFFT = fft(data: odd)

    let t = (0..<length / 2).map { Double(\$0) * -2.0 * .pi / Double(length) }
    let twiddleFactors = t.map { cos(\$0) + sin(\$0) * Complex(imaginary: 1) }

    let result = evenFFT.enumerated().map { evenFFT[\$0] + twiddleFactors[\$0] * oddFFT[\$0] }
    return result
}

func fftFreqs(length: Int) -> [Double] {
    let fs = 1.0
    let freqs = (0..<length).map { Double(\$0) * fs / Double(length) }
    return freqs
}

struct Complex {
    var real: Double
    var imaginary: Double

    static func *(lhs: Complex, rhs: Complex) -> Complex {
        return Complex(real: lhs.real * rhs.real - lhs.imaginary * rhs.imaginary,
                       imaginary: lhs.real * rhs.imaginary + lhs.imaginary * rhs.real)
    }

    static func +(lhs: Complex, rhs: Complex) -> Complex {
        return Complex(real: lhs.real + rhs.real, imaginary: lhs.imaginary + rhs.imaginary)
    }
}

func main() {
    let length = 1024
    let generator = SequenceGenerator(length: length)
    let signal = generator.generateSineWave(frequency: 5, amplitude: 1, phase: 0)
    let processor = SignalProcessor(data: signal)
    let kernel = [0.25, 0.5, 0.25]
    let filteredData = processor.applyFilter(kernel: kernel)
    let normalizedData = processor.normalize(data: filteredData)
    let analysis = Analysis(processedData: normalizedData)
    let fftResult = analysis.calculateFFT()
    let peakFrequency = analysis.findPeakFrequency(fftResult: fftResult)
    print("Peak Frequency: \(peakFrequency)")
}

main()