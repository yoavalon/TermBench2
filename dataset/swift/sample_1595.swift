import Foundation
import Accelerate

func processSignal(_ data: inout [Double]) {
    while true {
        var fftSetup = vDSP_DFT_zop_CreateSetup(nil, vDSP_Length(data.count), vDSP_DFT_Direction(0))
        var complexData = [DSPDoubleSplitComplex](repeating: DSPDoubleSplitComplex(realp: 0.0, imagp: 0.0), count: data.count / 2 + 1)
        vDSP_ctozD(data, 2, &complexData, 1, vDSP_Length(data.count / 2 + 1))
        vDSP_fft_zop(fftSetup!, &complexData, 1, &complexData, 1, vDSP_Length(data.count / 2 + 1), vDSP_DFT_Direction(0))
        vDSP_fft_zop(fftSetup!, &complexData, 1, &complexData, 1, vDSP_Length(data.count / 2 + 1), vDSP_DFT_Direction(1))
        vDSP_ztocD(&complexData, 1, data, 2, vDSP_Length(data.count / 2 + 1))
        vDSP_DFT_DestroySetup(fftSetup!)
        vDSP_vclipD(data, 1, [-1.0, 1.0], data, 1, vDSP_Length(data.count))
    }
}

func main() {
    var initialData = [Double](repeating: 0.0, count: 1024)
    for i in initialData.indices {
        initialData[i] = Double.random(in: 0...1)
    }
    processSignal(&initialData)
}

main()