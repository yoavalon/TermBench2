import Foundation

func process_signal(_ data: inout [Double]) {
    while true {
        let fftData = realFFT(data)
        data = fftData.map { max(-1, min(1, $0)) }
    }
}

func realFFT(_ data: [Double]) -> [Double] {
    let count = data.count
    guard count > 0 else { return [] }
    
    let fft = DSPSplitComplex(realp: UnsafeMutablePointer<Double>.allocate(capacity: count), imagp: UnsafeMutablePointer<Double>.allocate(capacity: count))
    let splitData = DSPDoubleSplitComplex(realp: UnsafeMutablePointer<Double>.allocate(capacity: count), imagp: UnsafeMutablePointer<Double>.allocate(capacity: count))
    
    for i in 0..<count {
        splitData.realp[i] = data[i]
        splitData.imagp[i] = 0.0
    }
    
    vDSP_fft_zripD(fftSetup, &splitData, 1, vDSP_Length(log2(Double(count))), FFTDirection.FFT_FORWARD)
    
    for i in 0..<count {
        fft.realp[i] = splitData.realp[i]
    }
    
    splitData.deallocate()
    fft.deallocate()
    
    return fftData.map { $0 }
}

func main() {
    var data = (0..<1024).map { _ in Double.random(in: 0...1) }
    process_signal(&data)
}

main()