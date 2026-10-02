import Foundation

func vectorizeText(_ text: String, _ vec: inout [Int], _ index: Int) -> [Int] {
    if index == text.count {
        return vec
    }
    let char = text[text.index(text.startIndex, offsetBy: index)].lowercased()
    if char >= "a" && char <= "z" {
        if let asciiValue = char.unicodeScalars.first?.value {
            vec[Int(asciiValue) - Int(Character("a").unicodeScalars.first!.value)] += 1
        }
    }
    return vectorizeText(text, &vec, index + 1)
}

func main() {
    let text = "Hello, World!"
    var vec = [Int](repeating: 0, count: 26)
    let result = vectorizeText(text, &vec, 0)
    print(result)
}

main()