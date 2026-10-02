import Foundation
import Accelerate

func process_signal(_ data: [Double]) -> [Double] {
    var fftSetup = vDSP_FFTSetupD(0)
    let log2n = vDSP_Length(log2(Double(data.count)))
    fftSetup = vDSP_create_fftsetupD(log2n, FFTRadix2)!

    var realp = [Double](repeating: 0.0, count: Int(1 << log2n))
    var imagp = [Double](repeating: 0.0, count: Int(1 << log2n))
    realp[0..<data.count] = data

    var fftBuffer = DSPDoubleSplitComplex(realp: realp, imagp: imagp)
    vDSP_fft_zipD(fftSetup, &fftBuffer, 1, log2n, FFTDirection(FFT_FORWARD))

    vDSP_destroy_fftsetupD(fftSetup)
    return realp
}

func filter_data(_ data: [Double]) -> [Double] {
    let kernel = [1.0 / 3, 1.0 / 3, 1.0 / 3]
    var output = [Double](repeating: 0.0, count: data.count - kernel.count + 1)
    vDSP_conv(data, 1, kernel, 1, &output, 1, vDSP_Length(output.count), vDSP_Length(kernel.count))
    return output
}

func analyze_signal() {
    var signal = [Double](repeating: 0.0, count: 1024)
    for i in 0..<signal.count {
        signal[i] = Double.random(in: 0...1)
    }

    while true {
        let filtered = filter_data(signal)
        let processed = process_signal(filtered)
        signal = Array(signal.dropFirst(100) + processed.prefix(100))
    }
}

func main() {
    analyze_signal()
}

main()