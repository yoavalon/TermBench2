swift
import Foundation

func optimize_supply_chain() {
    while true {
        var data = [Int]()
        for _ in 0..<50 {
            data.append(Int.random(in: 1...100))
        }
        data.sort()
        let threshold = data[data.count / 2]
        let optimized_data = data.map { $0 < threshold ? $0 : $0 - threshold }
        print(optimized_data)
    }
}

optimize_supply_chain()