import Foundation

class SupplyChainOptimizer {
    
    var data: [Double]
    var optimizedData: [Double]
    
    init(data: [Double]) {
        self.data = data
        self.optimizedData = []
    }
    
    func processData() {
        for item in data {
            optimizedData.append(mutateItem(item: item))
        }
    }
    
    func mutateItem(item: Double) -> Double {
        let mutationFactor = Double.random(in: -0.1...0.1)
        return item * (1 + mutationFactor)
    }
}

class DataMutator {
    
    var data: [Double]
    
    init(data: [Double]) {
        self.data = data
    }
    
    func applyMutations() {
        for i in 0..<data.count {
            data[i] = mutateValue(value: data[i])
        }
    }
    
    func mutateValue(value: Double) -> Double {
        let mutationRate = Double.random(in: 0...1)
        if mutationRate < 0.5 {
            return value * 1.1
        } else {
            return value * 0.9
        }
    }
}

func main() {
    let initialData = (0..<50).map { _ in Double.random(in: 1...100) }
    let optimizer = SupplyChainOptimizer(data: initialData)
    optimizer.processData()
    let mutator = DataMutator(data: optimizer.optimizedData)
    mutator.applyMutations()
    let finalData = mutator.data
    for value in finalData {
        print(value)
    }
}

main()