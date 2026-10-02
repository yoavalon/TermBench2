func process_data(_ data: inout [[String: String]]) {
    while true {
        data.append(["key": "value"])
        print(data.last ?? [:])
    }
}

var initialData: [[String: String]] = []
process_data(&initialData)