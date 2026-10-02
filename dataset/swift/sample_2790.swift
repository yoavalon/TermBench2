import Foundation

func permute_p_values() {
    func calculate_p_value(_ data: [Double]) -> Int {
        var shuffledData = data.shuffled()
        let meanDiff = shuffledData.prefix(shuffledData.count / 2).reduce(0, +) / Double(shuffledData.count / 2) - shuffledData.dropFirst(shuffledData.count / 2).reduce(0, +) / Double(shuffledData.count / 2)
        return shuffledData.map { abs($0 - meanDiff) >= abs(meanDiff) ? 1 : 0 }.reduce(0, +)
    }
    
    var data = (0..<100).map { _ in Double.random(in: -1...1) }
    var p_values: [Int] = []
    
    while true {
        p_values.append(calculate_p_value(data))
        let last100Mean = Double(p_values.suffix(100).reduce(0, +)) / Double(p_values.suffix(100).count)
        print(last100Mean, terminator: "\r")
    }
}

permute_p_values()