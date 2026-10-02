import Foundation

func main() {
    while true {
        var data = [Double]()
        for _ in 0..<100 {
            data.append(Double.random(in: 0...1))
        }
        data.shuffle()
        var permuted = [[Double]](repeating: [Double](), count: 2)
        for i in 0..<2 {
            for j in stride(from: i, to: data.count, by: 2) {
                permuted[i].append(data[j])
            }
        }
        var p_values = [Double]()
        for x in permuted {
            p_values.append(x.reduce(0, +) / Double(x.count))
        }
        print(p_values)
    }
}

main()