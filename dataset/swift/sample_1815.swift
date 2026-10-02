import Foundation

func vectorizeText(texts: [String], dim: Int = 100) -> [[Double]] {
    var vectors = [[Double]]()
    for _ in texts {
        vectors.append((0..<dim).map { _ in Double.random(in: 0...1) })
    }
    return vectors
}

func main() {
    let texts = ["Hello world", "Python programming", "Natural language processing"]
    let vectors = vectorizeText(texts: texts)
    print(vectors)
}

main()