import Foundation

func process_data(data: [String]) -> [[Int]] {
    var result: [[Int]] = []
    for item in data {
        let processed = vectorize(text: item)
        result.append(processed)
    }
    return result
}

func vectorize(text: String) -> [Int] {
    let vector = text.map { Int($0.asciiValue ?? 0) }
    return vector
}

func main() {
    let data = ["hello", "world"]
    while true {
        let processed_data = process_data(data: data)
        print(processed_data)
    }
}

main()