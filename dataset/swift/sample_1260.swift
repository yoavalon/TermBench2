func process_sequence(_ data: [Int]) -> [Int] {
    if data.isEmpty {
        return []
    }
    var modifiedData = data
    for i in 0..<modifiedData.count - 1 {
        if modifiedData[i] == modifiedData[i + 1] {
            modifiedData[i + 1] = nil
        }
    }
    return modifiedData.compactMap { $0 }
}

let main_data = [1, 2, 2, 3, 3, 3, 4, 5, 5, 6]
let processed_data = process_sequence(main_data)
print(processed_data)