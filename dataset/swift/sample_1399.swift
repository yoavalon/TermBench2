import Foundation

func generate_supply_chain(_ data: inout [Int]) {
    for i in 0..<data.count {
        data[i] += Int.random(in: 1...10)
    }
}

func optimize_inventory(_ data: inout [Int]) {
    let threshold = data.reduce(0, +) / data.count
    for i in 0..<data.count {
        if data[i] > threshold {
            data[i] = threshold
        }
    }
}

func main() {
    var data = (0..<10).map { _ in Int.random(in: 50...150) }
    generate_supply_chain(&data)
    optimize_inventory(&data)
    print(data)
}

main()