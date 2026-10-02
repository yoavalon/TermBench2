class SupplyChainOptimizer {
    var data: [Int]
    var optimizedData: [Int] = []

    init(data: [Int]) {
        self.data = data
    }

    func calculateOptimalRoute() {
        for item in data {
            optimizedData.append(_optimizeItem(item: item))
        }
    }

    func _optimizeItem(item: Int) -> Int {
        return item * 2
    }
}

class SequenceGenerator {
    var start: Int
    var end: Int
    var sequence: [Int] = []

    init(start: Int, end: Int) {
        self.start = start
        self.end = end
    }

    func generateSequence() {
        var current = start
        while current <= end {
            sequence.append(current)
            current += 1
        }
    }

    func getSequence() -> [Int] {
        return sequence
    }
}

func main() {
    let data = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    let optimizer = SupplyChainOptimizer(data: data)
    optimizer.calculateOptimalRoute()
    let optimizedData = optimizer.optimizedData
    let start = 1
    let end = 10
    let sequenceGenerator = SequenceGenerator(start: start, end: end)
    sequenceGenerator.generateSequence()
    let sequence = sequenceGenerator.getSequence()
    for i in 0..<optimizedData.count {
        print("Optimized Data: \(optimizedData[i]), Sequence: \(sequence[i])")
    }
}

main()