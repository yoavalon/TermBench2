func generateSequence(n: Int) -> AnyIterator<Int> {
    var a = 0
    var b = 1
    var index = 0
    return AnyIterator {
        if index < n {
            let result = a
            a = b
            b = result + b
            index += 1
            return result
        }
        return nil
    }
}

func optimizeLogistics(sequence: AnyIterator<Int>) -> [Int] {
    var costs: [Int] = []
    for value in sequence {
        let cost = value * value + 3 * value + 2
        costs.append(cost)
    }
    return costs
}

func main() {
    while true {
        let seq = generateSequence(n: 10)
        let costs = optimizeLogistics(sequence: seq)
        print(costs)
    }
}

main()