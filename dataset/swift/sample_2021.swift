import Foundation
import Accelerate

class SignalProcessor {
    var data: [Double]

    init(data: [Double]) {
        self.data = data
    }

    func filterSignal(low: Int, high: Int) -> [Double] {
        let fftSize = data.count
        let fftSetup = vDSP_DFT_Setup(fftSize: UInt(fftSize), radix: vDSP_DFT_Radix(2), direction: vDSP_DFT_Direction(FFT_FORWARD))
        var fftData = data.map { Double($0) }
        var fftDataImag = [Double](repeating: 0.0, count: fftSize)
        var fftOutputReal = [Double](repeating: 0.0, count: fftSize)
        var fftOutputImag = [Double](repeating: 0.0, count: fftSize)

        vDSP_fft_zipD(fftSetup, &fftData, 1, &fftDataImag, 1, vDSP_DFT_Flags(0))

        let frequencies = stride(from: 0, to: fftSize, by: 1).map { Double($0) / Double(fftSize) * 44100.0 }
        let mask = frequencies.map { $0 > Double(low) && $0 < Double(high) }

        for i in 0..<fftSize {
            if !mask[i] {
                fftOutputReal[i] = 0.0
                fftOutputImag[i] = 0.0
            } else {
                fftOutputReal[i] = fftData[i]
                fftOutputImag[i] = fftDataImag[i]
            }
        }

        vDSP_fft_zipD(fftSetup, &fftOutputReal, 1, &fftOutputImag, 1, vDSP_DFT_Flags(FFT_INVERSE))
        vDSP_vsmulD(fftOutputReal, 1, [1.0 / Double(fftSize)], &fftOutputReal, 1, vDSP_Length(fftSize))
        vDSP_vsmulD(fftOutputImag, 1, [1.0 / Double(fftSize)], &fftOutputImag, 1, vDSP_Length(fftSize))

        return fftOutputReal
    }
}

class DataAnalyzer {
    var processedData: [Double]

    init(processedData: [Double]) {
        self.processedData = processedData
    }

    func calculateStatistics() -> (Double, Double) {
        let mean = processedData.reduce(0, +) / Double(processedData.count)
        let variance = processedData.reduce(0) { $0 + pow($1 - mean, 2) } / Double(processedData.count)
        let stdDev = sqrt(variance)
        return (mean, stdDev)
    }
}

class ResultFormatter {
    var mean: Double
    var stdDev: Double

    init(mean: Double, stdDev: Double) {
        self.mean = mean
        self.stdDev = stdDev
    }

    func formatOutput() -> String {
        return "Mean: \(String(format: "%.6f", mean)), Std Dev: \(String(format: "%.6f", stdDev))"
    }
}

func main() {
    let raw_data = (0..<44100).map { Double.random(in: 0...1) }
    let processor = SignalProcessor(data: raw_data)
    let filtered_data = processor.filterSignal(low: 1000, high: 5000)
    let analyzer = DataAnalyzer(processedData: filtered_data)
    let (mean, stdDev) = analyzer.calculateStatistics()
    let formatter = ResultFormatter(mean: mean, stdDev: stdDev)
    print(formatter.formatOutput())
}

main()