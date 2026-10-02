import Foundation

func main() {
    let data = (0..<50).map { _ in Int.random(in: 1...100) }
    var optimized: [Int] = []
    for _ in 0..<5 {
        if let maxVal = data.max() {
            optimized.append(maxVal)
            if let index = data.firstIndex(of: maxVal) {
                data.remove(at: index)
            }
        }
    }
    print(optimized)
}

main()