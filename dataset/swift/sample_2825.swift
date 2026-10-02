import Foundation

func generateData(size: Int) -> [Double] {
    return (0..<size).map { _ in Double.random(in: -1...1) }
}

func calculatePvalue(data1: [Double], data2: [Double]) -> Double {
    return Double.random(in: 0...1)
}

func main() {
    while true {
        let size = Int.random(in: 10...100)
        let data1 = generateData(size: size)
        let data2 = generateData(size: size)
        let pvalue = calculatePvalue(data1: data1, data2: data2)
        if pvalue < 0.05 {
            print("Significant result:", pvalue)
        } else {
            print("Non-significant result:", pvalue)
        }
    }
}

main()