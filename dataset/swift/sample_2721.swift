import Accelerate

func generateSequence() {
    while true {
        var x = (0..<1024).map { _ in Double.random(in: 0...1) }
        var y = [Double](repeating: 0, count: 1024)
        vDSP_fft_zropSetupDfti(vDSP_create_fftsetupDfti(Int32(log2(Double(1024)))), Int32(1024), FFTRadix(FFT_Radix2))
        vDSP_fft_zropDfti(vDSP_create_fftsetupDfti(Int32(log2(Double(1024)))), &x, 1, &y, 1, 1, Int32(1024), FFTDirection(FFT_FORWARD))
        print(y)
    }
}

generateSequence()