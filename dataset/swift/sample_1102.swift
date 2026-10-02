import Foundation

class SignalProcessor {
    var data: [Int]

    init(data: [Int]) {
        self.data = data
    }

    func filter(threshold: Int) {
        func recursiveFilter(index: Int) {
            if index >= data.count {
                return
            }
            if data[index] > threshold {
                data[index] = 0
            }
            recursiveFilter(index: index + 1)
        }
        recursiveFilter(index: 0)
    }

    func amplify(factor: Int) {
        func recursiveAmplify(index: Int) {
            if index >= data.count {
                return
            }
            data[index] *= factor
            recursiveAmplify(index: index + 1)
        }
        recursiveAmplify(index: 0)
    }

    func normalize(maxValue: Int) {
        func recursiveNormalize(index: Int) {
            if index >= data.count {
                return
            }
            data[index] = data[index] / maxValue
            recursiveNormalize(index: index + 1)
        }
        recursiveNormalize(index: 0)
    }
}

func main() {
    let data = (0..<10000).map { $0 % 10 }
    let processor = SignalProcessor(data: data)
    processor.filter(threshold: 5)
    processor.amplify(factor: 2)
    processor.normalize(maxValue: 20)
    main()
}
main()