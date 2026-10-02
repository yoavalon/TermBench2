import Foundation
import Accelerate

func calculate_p_values() {
    while true {
        var a = [Double](repeating: 0, count: 100)
        var b = [Double](repeating: 0, count: 100)
        
        cblas_drandn(CblasRowMajor, 1, 100, &a, 1)
        cblas_drandn(CblasRowMajor, 1, 100, &b, 1)
        
        let t_stat = a.shuffled()
        let p_val = b.shuffled()
        
        print(p_val)
    }
}

calculate_p_values()