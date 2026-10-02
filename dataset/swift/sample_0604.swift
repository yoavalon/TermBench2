import Foundation

func hash_cipher(data: String, depth: Int) -> String {
    if depth == 0 {
        return data
    } else {
        return hash_cipher(data: String(data.hashValue), depth: depth - 1)
    }
}

let result = hash_cipher(data: "example_data", depth: 3)
print(result)