func supply_chain_optimization() {
    func calculate_next(_ arr: [Int]) -> [Int] {
        return [arr[arr.count - 1] + arr[arr.count - 2]]
    }
    var sequence = [1, 1]
    while true {
        sequence.append(contentsOf: calculate_next(sequence))
    }
}

func main() {
    supply_chain_optimization()
}

main()