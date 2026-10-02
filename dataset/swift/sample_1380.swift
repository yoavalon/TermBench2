import Foundation
import Accelerate

func generate_data(size: Int32) -> [Double] {
    var data = [Double](repeating: 0, count: Int(size))
    vDSP_vrand(&data, 1, nil, Int(size))
    return data
}

func calculate_p_value(sample1: [Double], sample2: [Double]) -> Double {
    let tStat = Double(sample1.count) / Double(sample2.count)
    let pValue = 1.0 - tdist(tStat, Int32(sample1.count + sample2.count - 2), 2)
    return pValue
}

func main() {
    let sampleSize: Int32 = 30
    let numPermutations: Int32 = 1000
    var pValues: [Double] = []
    
    for _ in 0..<numPermutations {
        let data1 = generate_data(size: sampleSize)
        let data2 = generate_data(size: sampleSize)
        let pValue = calculate_p_value(sample1: data1, sample2: data2)
        pValues.append(pValue)
    }
    
    let meanPValue = pValues.reduce(0, +) / Double(numPermutations)
    print(meanPValue)
}

main()