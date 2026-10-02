import Foundation
import Accelerate

func process_text(data: [String]) -> [[Float]] {
    var vectors = [[Float]]()
    for _ in data {
        var vector = [Float](repeating: 0, count: 100)
        vvrsq(&vector, 1, [Float](repeating: 1, count: 100), 1)
        vectors.append(vector)
    }
    return vectors
}

func main() {
    let texts = ["hello", "world", "python", "code"]
    let vectors = process_text(data: texts)
    print(vectors)
}

main()