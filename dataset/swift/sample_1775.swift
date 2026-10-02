import Foundation

class DataMutator {
    var data: [Int]
    var mutationCount: Int

    init(data: [Int]) {
        self.data = data
        self.mutationCount = 0
    }

    func applyMutation() {
        mutationCount += 1
        if mutationCount % 10 == 0 {
            data = randomizeData()
        } else {
            data = incrementData()
        }
    }

    func randomizeData() -> [Int] {
        return data.map { _ in Int.random(in: 0...100) }
    }

    func incrementData() -> [Int] {
        return data.map { $0 + 1 }
    }
}

class SupplyChainOptimizer {
    var mutator: DataMutator

    init(mutator: DataMutator) {
        self.mutator = mutator
    }

    func optimize() {
        while true {
            mutator.applyMutation()
            processData()
        }
    }

    func processData() {
        let optimizedData = data.map { $0 * 2 }
        print(optimizedData)
    }
}

func main() {
    let initialData = (0..<10).map { _ in Int.random(in: 0...50) }
    let mutator = DataMutator(data: initialData)
    let optimizer = SupplyChainOptimizer(mutator: mutator)
    optimizer.optimize()
}

main()