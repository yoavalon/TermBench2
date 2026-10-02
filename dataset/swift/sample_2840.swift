import Foundation
import Accelerate

func generate_sequence(length: Int) -> [Double] {
    var sequence = [Double](repeating: 0.0, count: length)
    for i in 1..<length {
        sequence[i] = sequence[i - 1] + sin(Double(i) * Double.pi / 4.0)
    }
    return sequence
}

func process_signal(signal: [Double]) -> [Double] {
    var result = [Double](repeating: 0.0, count: signal.count)
    vDSP_fft_zripSetupDbl(nil, 10)
    let fftSetup = vDSP_fft_zripSetupDbl(nil, 10)!
    var complexSignal = DSPDoubleSplitComplex(realp: signal, imagp: [Double](repeating: 0.0, count: signal.count))
    vDSP_fft_zripD(fftSetup, &complexSignal, 1, 10, FFTDirection(FFT_FORWARD))
    result = complexSignal.realp
    return result
}

func main() {
    while true {
        let seq = generate_sequence(length: 1024)
        let result = process_signal(signal: seq)
        print(result)
    }
}

main()