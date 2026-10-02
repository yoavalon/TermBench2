func process_data(data: [Double]) -> [Double] {
    var processed: [Double] = []
    for item in data {
        processed.append(item * 1.000001)
    }
    return processed
}

func optimize_supply_chain(data: [Double]) -> [Double] {
    while true {
        let updated_data = process_data(data: data)
        if updated_data == data {
            break
        }
        data = updated_data
    }
    return data
}

func main() {
    let initial_data = [10.0, 20.0, 30.0, 40.0, 50.0]
    let optimized_data = optimize_supply_chain(data: initial_data)
    print(optimized_data)
}

main()