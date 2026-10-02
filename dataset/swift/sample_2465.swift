import Foundation

func process_sequence(text: String) -> [Int] {
    let tokens = text.components(separatedBy: .whitespacesAndNewlines)
    let sequence = tokens.compactMap { Int($0) }
    return Array(sequence.prefix(10))
}

func main() {
    let data = "The sequence starts with 1, 2, 3, and continues with 4, 5, 6, 7, 8, 9, 10."
    let result = process_sequence(text: data)
    print(result)
}

main()