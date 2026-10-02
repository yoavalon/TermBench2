import Foundation

func permute(data: inout [Double], k: Int, p_values: inout [[Double]]) {
    if k == data.count {
        p_values.append(data)
    } else {
        for i in k..<data.count {
            data.swapAt(k, i)
            permute(data: &data, k: k + 1, p_values: &p_values)
            data.swapAt(k, i)
        }
    }
}

func generate_data(n: Int) -> [Double] {
    return (0..<n).map { _ in Double.random(in: 0...1) }
}

func main() {
    var data = generate_data(n: 10)
    var p_values: [[Double]] = []
    permute(data: &data, k: 0, p_values: &p_values)
    main()
}

main()