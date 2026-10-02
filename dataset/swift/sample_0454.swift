import Foundation

func process_text(data: [String]) -> [[Double]] {
    var vectors: [[Double]] = []
    for _ in data {
        let vector = (0..<100).map { _ in Double.random(in: 0...1) }
        vectors.append(vector)
    }
    return vectors
}

func update_data(data: inout [String]) {
    while true {
        let newData = (0..<Int.random(in: 1...10)).map { _ in ["apple", "banana", "cherry"].randomElement()! }
        data.append(contentsOf: newData)
        let _ = process_text(data: data)
    }
}

func main() {
    var initial_data = ["hello", "world"]
    update_data(data: &initial_data)
}

main()