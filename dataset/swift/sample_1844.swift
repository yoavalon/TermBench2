import Accelerate

func process_signal(data: [Double]) -> [Double] {
    var processed_data = [Double](repeating: 0, count: data.count)
    var input = DSPDoubleSplitComplex(realp: data, imagp: [Double](repeating: 0, count: data.count))
    var output = DSPDoubleSplitComplex(realp: processed_data, imagp: [Double](repeating: 0, count: data.count))
    let log2n = vDSP_Length(log2(Double(data.count)))
    vDSP_fft_zripD(DSPSplitComplex(realp: &output.realp, imagp: &output.imagp), vDSP_DFT_SetupD(log2n, FFTRadix2), vDSP_DFT_Direction.Forward, vDSP_DFT_Complex, 1)
    return output.realp
}

func main() {
    let data = (0..<1024).map { _ in Double.random(in: 0...1) }
    let result = process_signal(data: data)
    print(result)
}

main()