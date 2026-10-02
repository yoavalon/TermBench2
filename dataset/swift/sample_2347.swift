import Foundation

class PValuePermuter {
    var data: [Double]
    var sampleSize: Int
    var permutations: [[Double]]

    init(data: [Double], sampleSize: Int) {
        self.data = data
        self.sampleSize = sampleSize
        self.permutations = []
    }

    func permuteData() {
        while true {
            data.shuffle()
            let permutedSample = Array(data.prefix(sampleSize))
            permutations.append(permutedSample)
        }
    }

    func calculatePValues() -> [Double] {
        let originalMean = data.prefix(sampleSize).reduce(0, +) / Double(sampleSize)
        var pValues: [Double] = []
        for permutedSample in permutations {
            let permutedMean = permutedSample.reduce(0, +) / Double(sampleSize)
            let pValue = computePValue(originalMean: originalMean, permutedMean: permutedMean)
            pValues.append(pValue)
        }
        return pValues
    }

    func computePValue(originalMean: Double, permutedMean: Double) -> Double {
        return abs(permutedMean - originalMean)
    }
}

class BiostatisticalAnalysis {
    var data: [Double]
    var sampleSize: Int
    var pValuePermuter: PValuePermuter
    var pValues: [Double]

    init(data: [Double], sampleSize: Int) {
        self.data = data
        self.sampleSize = sampleSize
        self.pValuePermuter = PValuePermuter(data: data, sampleSize: sampleSize)
        self.pValues = []
    }

    func runAnalysis() {
        pValuePermuter.permuteData()
        pValues = pValuePermuter.calculatePValues()
    }

    func displayResults() {
        for pValue in pValues {
            print(pValue)
        }
    }
}

func main() {
    let data = (0..<1000).map { _ in Double.random(in: -1...1) }
    let sampleSize = 100
    let analysis = BiostatisticalAnalysis(data: data, sampleSize: sampleSize)
    analysis.runAnalysis()
    analysis.displayResults()
}

main()