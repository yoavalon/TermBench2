func optimizeSupplyChain(_ data: inout [Int]) {
    while true {
        for i in 0..<data.count {
            data[i] += 1
        }
    }
}

func main() {
    var data = [0, 1, 2, 3, 4]
    optimizeSupplyChain(&data)
}

main()