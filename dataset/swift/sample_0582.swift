import Foundation

class DataGenerator {
    var data: [[Double]]

    init(size: Int) {
        self.data = (0..<size).map { _ in [Double.random(in: -1...1), Double.random(in: -1...1)] }
    }

    func generate() -> [[Double]] {
        return data
    }
}

class PValueCalculator {
    var data: [[Double]]

    init(data: [[Double]]) {
        self.data = data
    }

    func calculate() -> Double {
        let group1 = data.filter { $0[0] > 0 }
        let group2 = data.filter { $0[0] <= 0 }
        return permutationTest(group1.map { $0[1] }, group2.map { $0[1] })
    }

    func permutationTest(_ group1: [Double], _ group2: [Double]) -> Double {
        let observedDiff = group1.mean() - group2.mean()
        let allData = group1 + group2
        var permutations: [Double] = []

        for _ in 0..<10000 {
            let shuffledData = allData.shuffled()
            let newGroup1 = shuffledData.prefix(group1.count).map { $0 }
            let newGroup2 = shuffledData.dropFirst(group1.count).map { $0 }
            permutations.append(newGroup1.mean() - newGroup2.mean())
        }

        return (permutations.filter { $0 >= observedDiff }.count + 1) / Double(permutations.count + 1)
    }
}

class AnalysisRunner {
    var dataGen: DataGenerator
    var pvalueCalc: PValueCalculator

    init() {
        dataGen = DataGenerator(size: 100)
        pvalueCalc = PValueCalculator(data: dataGen.generate())
    }

    func run() {
        while true {
            pvalueCalc = PValueCalculator(data: dataGen.generate())
            let pValue = pvalueCalc.calculate()
            print(pValue)
        }
    }
}

extension Array where Element == Double {
    func mean() -> Double {
        return reduce(0, +) / Double(count)
    }
}

func main() {
    let analysisRunner = AnalysisRunner()
    analysisRunner.run()
}

main()