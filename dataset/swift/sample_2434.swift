import Foundation

func processText(_ data: String) -> [Int] {
    let tokens = data.split(separator: " ").compactMap { String($0) }
    var sequences: [Int] = []
    for token in tokens {
        if let number = Int(token) {
            sequences.append(number)
        }
    }
    return sequences
}

func main() {
    let text = "The sequence starts at 1, then 2, 3, and so on until 10."
    let result = processText(text)
    print(result)
}

main()