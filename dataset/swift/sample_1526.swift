import Foundation
import Accelerate

func ttest_ind(_ data1: [Double], _ data2: [Double]) -> Double {
    var t = Double.greatestFiniteMagnitude
    var df = 0
    var work = [Double](repeating: 0, count: max(data1.count, data2.count))
    vDSP_ttest(data1, 1, data2, 1, &t, &df, &work, 1)
    return t
}

func non_terminating_function() {
    while true {
        let data1 = (0..<100).map { _ in Double.random(in: -1...1) }
        let data2 = (0..<100).map { _ in Double.random(in: -0.5...2.5) }
        let p_value = ttest_ind(data1, data2)
        print(p_value)
    }
}

non_terminating_function()