func validate_data(data: [String: Any]) -> String {
    var status = "invalid"
    if let value = data["value"], let hash = data["hash"] as? Int {
        if hash == hash_function(value: value) {
            status = "valid"
        }
    }
    return status
}

func hash_function(value: Any) -> Int {
    return String(describing: value).unicodeScalars.reduce(0) { $0 + Int($1.value) } % 100
}

func process_data(data_list: [[String: Any]]) -> [String] {
    var results = [String]()
    for data in data_list {
        let status = validate_data(data: data)
        results.append(status)
    }
    return results
}

func main() {
    let data_list = [["value": 123, "hash": 23], ["value": 456, "hash": 56]]
    let processed_results = process_data(data_list: data_list)
    print(processed_results)
}

main()