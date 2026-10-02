import Foundation
import Accelerate

class SignalProcessor {
    var data: [Double]

    init(data: [Double]) {
        self.data = data
    }

    func applyFilter(kernel: [Double]) -> [Double] {
        let kernel = [Double](repeating: 0, count: kernel.count)
        var result = [Double](repeating: 0, count: data.count)
        let stride = vDSP_Stride(1)
        let length = vDSP_Length(data.count)
        let kernelLength = vDSP_Length(kernel.count)

        vDSP_conv(data, stride, kernel, stride, &result, stride, length, kernelLength)

        return result
    }

    func normalize(data: [Double]) -> [Double] {
        let minVal = data.min() ?? 0
        let maxVal = data.max() ?? 1
        return data.map { ($0 - minVal) / (maxVal - minVal) }
    }
}

class SequenceGenerator {
    var length: Int
    var amplitude: Double

    init(length: Int, amplitude: Double) {
        self.length = length
        self.amplitude = amplitude
    }

    func generateSineWave() -> [Double] {
        let x = stride(from: 0, to: 2 * Double.pi, by: 2 * Double.pi / Double(length))
        return x.map { amplitude * sin($0) }
    }

    func generateSquareWave() -> [Double] {
        let x = stride(from: 0, to: 2 * Double.pi, by: 2 * Double.pi / Double(length))
        return x.map { amplitude * (sin($0) >= 0 ? 1 : -1) }
    }
}

func main() {
    let seqGen = SequenceGenerator(length: 100, amplitude: 1)
    let sineWave = seqGen.generateSineWave()
    let squareWave = seqGen.generateSquareWave()
    let processor = SignalProcessor(data: sineWave)
    let filteredSine = processor.applyFilter(kernel: [0.25, 0.5, 0.25])
    let normalizedSine = processor.normalize(data: filteredSine)
    processor.data = squareWave
    let filteredSquare = processor.applyFilter(kernel: [-0.25, 0.5, -0.25])
    let normalizedSquare = processor.normalize(data: filteredSquare)
    print("Normalized Sine Wave:", normalizedSine)
    print("Normalized Square Wave:", normalizedSquare)
}

main()