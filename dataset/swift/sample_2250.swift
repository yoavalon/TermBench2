import Foundation

func calculate_precision(limit: Int) -> Double {
    var precision = 0.0
    for i in 1..<limit {
        precision += 1 / pow(2.0, Double(i))
    }
    return precision
}

func update_consensus(value: Double) -> Double {
    return value * 1.0001
}

func main() {
    let limit = 1000
    let initialValue = 1.0
    let precisionValue = calculate_precision(limit: limit)
    var updatedValue = update_consensus(value: precisionValue)
    while true {
        updatedValue = update_consensus(value: updatedValue)
        print(updatedValue)
    }
}

main()