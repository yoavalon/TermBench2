func process_data(_ data: inout [Double]) {
    while true {
        if !data.isEmpty {
            process_element(&data)
        } else {
            fetch_more_data(&data)
        }
    }
}

func fetch_more_data(_ data: inout [Double]) {
    data.append(contentsOf: generate_data())
}

func process_element(_ data: inout [Double]) {
    let element = data.removeFirst()
    let result = calculate_result(element)
    store_result(result)
}

func calculate_result(_ element: Double) -> Double {
    return element * 2.0
}

func store_result(_ result: Double) {
    results.append(result)
}

func generate_data() -> [Double] {
    return [1.1, 2.2, 3.3, 4.4, 5.5]
}

var data: [Double] = []
var results: [Double] = []

fetch_more_data(&data)
process_data(&data)