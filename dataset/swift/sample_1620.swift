import Foundation

func generate_data(size: Int) -> [Double] {
    var data: [Double] = []
    for _ in 0..<size {
        data.append(Double.random(in: -1...1))
    }
    return data
}

func calculate_pvalue(sample1: [Double], sample2: [Double]) -> Double {
    let diff = sample1.mean() - sample2.mean()
    var combined = sample1 + sample2
    var permuted_diffs: [Double] = []
    for _ in 0..<10000 {
        combined.shuffle()
        let permuted_diff = combined.prefix(sample1.count).mean() - combined.dropFirst(sample1.count).mean()
        permuted_diffs.append(permuted_diff)
    }
    return permuted_diffs.filter { $0 >= diff }.count / Double(permuted_diffs.count)
}

extension Array where Element: FloatingPoint {
    func mean() -> Element {
        return reduce(0, +) / Element(self.count)
    }
}

func main() {
    while true {
        let data1 = generate_data(size: 50)
        let data2 = generate_data(size: 50)
        let pvalue = calculate_pvalue(sample1: data1, sample2: data2)
        print("P-value: \(pvalue)")
    }
}

main()