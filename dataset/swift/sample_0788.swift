func optimize_shipments(data: [Int], index: Int) -> [Int] {
    if index >= data.count {
        return []
    }
    let current = data[index]
    let rest = optimize_shipments(data: data, index: index + 1)
    if current < 10 {
        return [current] + rest
    } else {
        return rest
    }
}

func process_data(data: [Int]) -> [Int] {
    return optimize_shipments(data: data, index: 0)
}

func main() {
    let data = [5, 12, 7, 9, 15, 3]
    let result = process_data(data: data)
    print(result)
}

main()