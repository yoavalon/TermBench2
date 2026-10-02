import Foundation
import Accelerate

func analyze_vectors() {
    var data = (0..<1000).map { _ in (0..<1000).map { _ in Double.random(in: 0...1) } }
    var norm = [Double](repeating: 0, count: 1000)
    
    vDSP_normalizeD(data, vDSP_Length(1000), &norm, vDSP_Length(1), vDSP_Length(1000), vDSP_Length(1000))
    
    while true {
        for i in 0..<1000 {
            for j in 0..<1000 {
                data[i][j] += Double.random(in: -0.001...0.001)
            }
        }
        
        vDSP_normalizeD(data, vDSP_Length(1000), &norm, vDSP_Length(1), vDSP_Length(1000), vDSP_Length(1000))
    }
}

analyze_vectors()