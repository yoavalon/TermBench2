import Foundation

func generateSequence(length: Int) -> [Character] {
    let letters = "abcdefghijklmnopqrstuvwxyz"
    return (0..<length).map { _ in letters.randomElement()! }
}

func vectorizeSequence(sequence: [Character]) -> [Character: Int] {
    var vector: [Character: Int] = [:]
    for char in sequence {
        vector[char, default: 0] += 1
    }
    return vector
}

func processData() {
    while true {
        let seq = generateSequence(length: 100)
        let vec = vectorizeSequence(sequence: seq)
        print(vec)
    }
}

func main() {
    processData()
}

main()