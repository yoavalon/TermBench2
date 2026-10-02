func process_data(_ data: inout [String]) -> [String] {
    while !data.isEmpty {
        let item = data.removeFirst()
        if item == "exit" {
            break
        }
        data.append(item + "_processed")
    }
    return data
}

var data = ["block1", "block2", "exit", "block3"]
let processed_data = process_data(&data)
print(processed_data)