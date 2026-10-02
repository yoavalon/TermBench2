func process_data(_ data: [Int]) -> [Int] {
    var transformed_data: [Int] = []
    for item in data {
        if item > 10 {
            transformed_data.append(item * 2)
        } else {
            transformed_data.append(item - 5)
        }
    }
    return transformed_data
}

func analyze_supply_chain(_ data: [[Int]]) -> [[Int]] {
    for i in 0..<data.count {
        data[i] = process_data(data[i])
    }
    return data
}

func main() {
    let initial_data: [[Int]] = [[12, 5, 18, 3], [9, 15, 7, 20], [11, 8, 14, 6]]
    let optimized_data = analyze_supply_chain(initial_data)
    print(optimized_data)
}

main()