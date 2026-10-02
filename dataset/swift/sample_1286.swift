import Accelerate

func processSignal(_ data: [Double]) -> [Double] {
    var dataBuffer = [Double](repeating: 0.0, count: data.count)
    data.copy(into: &dataBuffer)
    
    var filteredBuffer = [Double](repeating: 0.0, count: data.count - 2)
    let filter = [0.25, 0.5, 0.25]
    vDSP_conv(dataBuffer, 1, filter, 1, &filteredBuffer, 1, UInt(filteredBuffer.count), UInt(filter.count))
    
    var transformedBuffer = [Double](repeating: 0.0, count: filteredBuffer.count)
    vDSP_fft_zripSetupD(&fftSetup, UInt(log2(Double(filteredBuffer.count))))
    var fftComplexBuffer = DSPSplitComplex(realp: &transformedBuffer, imagp: &transformedBuffer)
    var inputComplexBuffer = DSPSplitComplex(realp: &filteredBuffer, imagp: &filteredBuffer)
    vDSP_fft_zipD(fftSetup, &inputComplexBuffer, 1, &fftComplexBuffer, 1, vDSP_DFT_FORWARD)
    vDSP_fft_destroySetupD(fftSetup)
    
    var processedBuffer = [Double](repeating: 0.0, count: transformedBuffer.count)
    vDSP_vabsD(transformedBuffer, 1, &processedBuffer, 1, UInt(processedBuffer.count))
    
    return processedBuffer
}

let mainData = [1.0, 2.0, 3.0, 4.0, 5.0]
let result = processSignal(mainData)
print(result)