import Foundation

func hashData(_ data: String) -> String {
    let hashObject = Insecure.SHA256()
    let hash = hashObject.hash(data)
    return hash.map { String(format: "%02hhx", $0) }.joined()
}

func mutateData(_ data: String, iterations: Int) -> String {
    var mutatedData = data
    for _ in 0..<iterations {
        mutatedData = hashData(mutatedData)
    }
    return mutatedData
}

func main() {
    let initialData = "seed"
    let iterations = 5
    let result = mutateData(initialData, iterations: iterations)
    print(result)
}

main()