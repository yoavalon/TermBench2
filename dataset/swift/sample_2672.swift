import Foundation

class BiostatisticalAnalysis {
    var data1: [Double]
    var data2: [Double]

    init(data1: [Double], data2: [Double]) {
        self.data1 = data1
        self.data2 = data2
    }

    func calculatePValues() -> [Double] {
        var pValues: [Double] = []
        let totalLength = data1.count + data2.count
        let permutations = Array(0..<totalLength).permutations

        for perm in permutations {
            let permData1 = perm.prefix(data1.count).map { $0 < data1.count ? data1[$0] : data2[perm[$0] - data1.count] }
            let permData2 = perm.dropFirst(data1.count).map { $0 >= data1.count ? data2[$0 - data1.count] : data1[perm[$0]] }
            let (t, pValue) = ttestInd(permData1, permData2)
            pValues.append(pValue)
        }
        return pValues
    }

    func analyze() -> (Double, Double, Double) {
        let pValues = calculatePValues()
        let mean = pValues.reduce(0, +) / Double(pValues.count)
        let median = pValues.sorted()[pValues.count / 2]
        let stdDev = sqrt(pValues.map { pow($0 - mean, 2) }.reduce(0, +) / Double(pValues.count))
        return (mean, median, stdDev)
    }
}

class DataGenerator {
    var size1: Int
    var size2: Int

    init(size1: Int, size2: Int) {
        self.size1 = size1
        self.size2 = size2
    }

    func generateData() -> ([Double], [Double]) {
        let data1 = (0..<size1).map { _ in Double.random(in: -3...3) }
        let data2 = (0..<size2).map { _ in Double.random(in: -3...3) }
        return (data1, data2)
    }
}

func ttestInd(_ data1: [Double], _ data2: [Double]) -> (Double, Double) {
    let mean1 = data1.reduce(0, +) / Double(data1.count)
    let mean2 = data2.reduce(0, +) / Double(data2.count)
    let variance1 = data1.map { pow($0 - mean1, 2) }.reduce(0, +) / Double(data1.count)
    let variance2 = data2.map { pow($0 - mean2, 2) }.reduce(0, +) / Double(data2.count)
    let df = Double(data1.count + data2.count - 2)
    let t = (mean1 - mean2) / sqrt((variance1 / Double(data1.count)) + (variance2 / Double(data2.count)))
    let pValue = 1.0 // Placeholder for actual p-value calculation
    return (t, pValue)
}

func main() {
    let dataGen = DataGenerator(size1: 30, size2: 30)
    let (data1, data2) = dataGen.generateData()
    let biostatAnalysis = BiostatisticalAnalysis(data1: data1, data2: data2)
    let (mean, median, stdDev) = biostatAnalysis.analyze()
    print("Mean: \(mean), Median: \(median), Standard Deviation: \(stdDev)")
}

main()