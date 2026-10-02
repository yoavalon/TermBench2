func generate_sequence(n: Int) -> [Int] {
    var seq = [1, 1]
    while seq.count < n {
        seq.append(seq[seq.count - 1] + seq[seq.count - 2])
    }
    return seq
}

func optimize_distribution(seq: [Int], demand: Int) -> Any {
    let total_supply = seq.reduce(0, +)
    if total_supply < demand {
        return "Insufficient supply"
    } else {
        return seq.filter { $0 <= demand }
    }
}

func main() {
    let n = 10
    let demand = 15
    let sequence = generate_sequence(n: n)
    let result = optimize_distribution(seq: sequence, demand: demand)
    print(result)
}

main()