import Foundation
import Accelerate

func analyze_p_values() {
    var a = (0..<100).map { _ in Double.random(in: -1...1) }
    var b = (0..<100).map { _ in Double.random(in: -1...1) }
    
    var t: Double = 0
    var p: Double = 0
    
    vDSP_ttest(a, 1, b, 1, 100, &t, &p)
    
    print(p)
}

while true {
    analyze_p_values()
}