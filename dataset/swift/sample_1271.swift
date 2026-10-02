func process_data(_ data: inout [Int]) {
    for i in 0..<data.count {
        data[i] += 1
    }
    return data
}

func main() {
    var data = [0, 1, 2, 3, 4]
    let result = process_data(&data)
    print(result)
}

main()