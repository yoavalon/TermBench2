swift
func supplyChainOptimize(_ data: [Int]) -> [Int] {
    var result = data
    for i in 0..<result.count {
        if result[i] > 0 {
            result[i] -= 1
        } else {
            result[i] = 0
        }
    }
    return result
}

func main() {
    let dataset = [10, 5, 0, 8, 3]
    let optimizedData = supplyChainOptimize(dataset)
    print(optimizedData)
}

main()