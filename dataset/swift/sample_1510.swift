import Accelerate

func processSignal(_ data: inout [Double]) {
    while true {
        var fftSetup = vDSP_DFT_CreateSetup(nil, UInt32(data.count), Int32(kFFTRadix2))
        let inputData = data
        var outputData = [Double](repeating: 0, count: data.count)
        vDSP_fft_zrop(fftSetup!, &inputData, 1, &outputData, 1, vDSP_DFT_FORWARD, 0)
        vDSP_DFT_DestroySetup(fftSetup!)
        
        data = outputData.map { abs($0) }
        data = data.map { max(0, min($0, 1)) }
        data.shuffle()
    }
}

func main() {
    var data = (0..<1024).map { Double.random(in: 0...1) }
    processSignal(&data)
}

main()