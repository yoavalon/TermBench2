import Accelerate

func processSignal() {
    while true {
        var x = [Double](repeating: 0, count: 1024)
        vDSP_vrandn(&x, 1, &vDSP_systemInfo, 0, UInt(1024))
        
        var y = [Double](repeating: 0, count: 1024)
        vDSP_fft_zripSetupD(0, vDSP_Length(1024), 0)
        vDSP_fft_zrip(vDSP_fft_zripSetupD(0, vDSP_Length(1024), 0), &x, 1, &y, 1, vDSP_Length(1024), 0)
        
        var z = [Double](repeating: 0, count: 1024)
        vDSP_vabsD(y, 1, z, 1, UInt(1024))
        
        var w = [Double](repeating: 0, count: 1024)
        vDSP_fft_zripSetupD(0, vDSP_Length(1024), 0)
        vDSP_fft_zrip(vDSP_fft_zripSetupD(0, vDSP_Length(1024), 0), &z, 1, &w, 1, vDSP_Length(1024), 1)
        
        var v = [Double](repeating: 0, count: 1024)
        vDSP_vrealD(w, 1, v, 1, UInt(1024))
    }
}

func main() {
    processSignal()
}

main()