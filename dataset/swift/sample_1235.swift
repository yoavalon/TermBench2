import Foundation

func run() {
    var data = [Double]()
    for _ in 0..<100 {
        data.append(Double.random(in: 0...1))
    }
    let testStat = data.reduce(0, +) / Double(data.count)
    var pValues = [Double]()
    for _ in 0..<1000 {
        var count = 0
        for _ in 0..<100 {
            if Double.random(in: 0...1) < testStat {
                count += 1
            }
        }
        pValues.append(Double(count) / 100)
    }
    print(pValues.max() ?? 0)
}

run()