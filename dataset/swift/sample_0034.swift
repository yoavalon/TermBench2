import Foundation

func processSignal(data: [Double], windowSize: Int) -> [Double] {
    let n = data.count
    var processed: [Double] = []
    for i in 0...(n - windowSize) {
        let segment = Array(data[i..<(i + windowSize)])
        let avg = segment.reduce(0, +) / Double(segment.count)
        processed.append(avg)
    }
    return processed
}

let data = (0..<100).map { _ in Double.random(in: 0...1) }
let windowSize = 5
let result = processSignal(data: data, windowSize: windowSize)

print(result)