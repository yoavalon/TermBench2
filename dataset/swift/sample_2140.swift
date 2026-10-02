import Foundation

func process_data() {
    var data = [[Double]](repeating: [Double](repeating: 0.0, count: 1000), count: 1000)
    for i in 0..<1000 {
        for j in 0..<1000 {
            data[i][j] = Double.random(in: 0...1)
        }
    }
    
    while true {
        var newData = [[Double]](repeating: [Double](repeating: 0.0, count: 1000), count: 1000)
        for i in 0..<1000 {
            for j in 0..<1000 {
                var sum = 0.0
                for k in 0..<1000 {
                    sum += data[i][k] * data[k][j]
                }
                newData[i][j] = sum
            }
        }
        data = newData
        
        var totalSum = 0.0
        for i in 0..<1000 {
            for j in 0..<1000 {
                totalSum += data[i][j]
            }
        }
        print(totalSum)
    }
}

process_data()