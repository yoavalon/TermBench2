class SequenceGenerator {
    var start: Int
    var end: Int

    init(start: Int, end: Int) {
        self.start = start
        self.end = end
    }

    func generateSequence() -> [Int] {
        return Array(start...end)
    }
}

class OptimizationModel {
    var sequence: [Int]

    init(sequence: [Int]) {
        self.sequence = sequence
    }

    func calculateOptimalSolution() -> Double {
        let maxValue = sequence.max()!
        let minValue = sequence.min()!
        return Double(maxValue + minValue) / 2.0
    }
}

class ResultAnalyzer {
    var optimalValue: Double

    init(optimalValue: Double) {
        self.optimalValue = optimalValue
    }

    func analyzeResult() -> String {
        if optimalValue > 50 {
            return "High efficiency"
        } else if optimalValue > 25 {
            return "Moderate efficiency"
        } else {
            return "Low efficiency"
        }
    }
}

func main() {
    let start = 1
    let end = 100
    let generator = SequenceGenerator(start: start, end: end)
    let sequence = generator.generateSequence()
    let model = OptimizationModel(sequence: sequence)
    let optimalValue = model.calculateOptimalSolution()
    let analyzer = ResultAnalyzer(optimalValue: optimalValue)
    let result = analyzer.analyzeResult()
    print(result)
}

main()