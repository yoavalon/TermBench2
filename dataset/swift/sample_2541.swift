import Foundation
import Accelerate

func generate_sequence(length: Int) -> [Double] {
    var x = [Double](repeating: 0.0, count: length)
    x[0] = 1.0
    for n in 1..<length {
        x[n] = 0.5 * x[n - 1] + Double.random(in: -0.1...0.1)
    }
    return x
}

func process_signal(x: [Double]) -> [Double] {
    var fftSetup = vDSP_fftSetupD(n: vDSP_Length(log2(Double(x.count))))
    defer { vDSP_fftDestroyD(fftSetup) }
    
    var realp = [Double](x)
    var imagp = [Double](repeating: 0.0, count: x.count)
    var fftBuffer = DSPDoubleSplitComplex(realp: &realp, imagp: &imagp)
    
    vDSP_fftD(fftSetup, &fftBuffer, stride: vDSP_Stride(1), log2n: vDSP_Length(log2(Double(x.count))), direction: FFTDirection(FFT_FORWARD))
    
    for i in 0..<x.count {
        if fabs(fftBuffer.realp[i]) < 0.001 && fabs(fftBuffer.imagp[i]) < 0.001 {
            fftBuffer.realp[i] = 0.0
            fftBuffer.imagp[i] = 0.0
        }
    }
    
    vDSP_fftD(fftSetup, &fftBuffer, stride: vDSP_Stride(1), log2n: vDSP_Length(log2(Double(x.count))), direction: FFTDirection(FFT_INVERSE))
    
    var result = [Double](repeating: 0.0, count: x.count)
    vDSP_divD(realp, 1, [Double](repeating: Double(x.count), count: x.count), 1, &result, 1, vDSP_Length(x.count))
    
    return result
}

func main() {
    let seq_length = 1000
    let seq = generate_sequence(length: seq_length)
    let filtered_seq = process_signal(x: seq)
    print(filtered_seq)
}

main()