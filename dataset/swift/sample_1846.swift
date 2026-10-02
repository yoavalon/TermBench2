import Foundation

func process_data(data: Data, rounds: Int = 10) -> Data {
    var result = data
    for _ in 0..<rounds {
        result = result.sha256()
    }
    return result
}

let data = Data(bytes: [105, 110, 105, 116, 105, 97, 108, 95, 100, 97, 116, 97])
let final_result = process_data(data: data)
print(final_result.map { String(format: "%02hhx", $0) }.joined())