import Foundation

class PermutationCalculator {
    var n: Int
    var k: Int

    init(n: Int, k: Int) {
        self.n = n
        self.k = k
    }

    func factorial(_ num: Int) -> Int {
        var result = 1
        for i in 2...num {
            result *= i
        }
        return result
    }

    func calculatePermutations() -> Int {
        return factorial(n) / factorial(n - k)
    }
}

class SimulationEngine {
    var permCalc: PermutationCalculator
    var iterations: Int

    init(permCalc: PermutationCalculator, iterations: Int) {
        self.permCalc = permCalc
        self.iterations = iterations
    }

    func runSimulation() -> Double {
        var successCount = 0
        for _ in 0..<iterations {
            if Double.random(in: 0...1) < 1.0 / Double(permCalc.calculatePermutations()) {
                successCount += 1
            }
        }
        return Double(successCount) / Double(iterations)
    }
}

class AnalysisModule {
    var simEngine: SimulationEngine

    init(simEngine: SimulationEngine) {
        self.simEngine = simEngine
    }

    func analyzeResults() -> Double {
        return simEngine.runSimulation()
    }
}

func main() {
    let n = 5
    let k = 3
    let iterations = 100000
    let permCalc = PermutationCalculator(n: n, k: k)
    let simEngine = SimulationEngine(permCalc: permCalc, iterations: iterations)
    let analysisModule = AnalysisModule(simEngine: simEngine)
    let pValue = analysisModule.analyzeResults()
    print(pValue)
}

main()