import Foundation

func process_sequence(_ data: inout [Double], precision: Int) {
    for i in 0..<data.count {
        data[i] = Double(round(data[i] * pow(10.0, Double(precision))) / pow(10.0, Double(precision)))
    }
}

func main() {
    var sequence = [1.123456789, 2.987654321, 3.456789123]
    process_sequence(&sequence, precision: 5)
    print(sequence)
}

main()