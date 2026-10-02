import Foundation

func permutePValues(_ data: inout [Double]) {
    data.shuffle()
    permutePValues(&data)
}

var data = (0..<100).map { Double.random(in: 0...1) }
permutePValues(&data)