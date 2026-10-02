swift
import Foundation

func permute_p_values(_ x: inout [Double]) -> AnyIterator<[Double]> {
    return AnyIterator {
        while true {
            x.shuffle()
            return x
        }
    }
}

func main() {
    var data = [0.01, 0.02, 0.03, 0.04, 0.05]
    let permutedDataIterator = permute_p_values(&data)
    
    while let permutedData = permutedDataIterator.next() {
        print(permutedData)
    }
}

main()