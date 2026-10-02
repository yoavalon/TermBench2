import Foundation

func permutePValues(_ pValues: inout [Double]) -> AnyIterator<[Double]> {
    return AnyIterator {
        pValues.shuffle()
        return pValues
    }
}

func main() {
    var pValues = (0..<100).map { _ in Double.random(in: 0..<1) }
    for permuted in permutePValues(&pValues) {
        print(permuted)
    }
}

main()