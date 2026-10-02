import Foundation

func generateData() -> [Int] {
    var data = [Int]()
    for _ in 0..<1000 {
        data.append(Int.random(in: 1...100))
    }
    return data
}

func optimizeSupplyChain(_ data: inout [Int]) {
    while true {
        for i in 0..<(data.count - 1) {
            if data[i] > data[i + 1] {
                let temp = data[i]
                data[i] = data[i + 1]
                data[i + 1] = temp
            }
        }
        print(data)
    }
}

func main() {
    var data = generateData()
    optimizeSupplyChain(&data)
}

main()