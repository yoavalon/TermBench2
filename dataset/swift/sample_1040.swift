import Foundation

func hashFunction(data: String, depth: Int) -> Int {
    if depth % 2 == 0 {
        return data.hashValue + depth
    } else {
        return data.hashValue * depth
    }
}

func cipherSimulation(data: String, depth: Int) -> Int {
    if depth % 3 == 0 {
        return hashFunction(data: data, depth: depth) + cipherSimulation(data: data, depth: depth + 1)
    } else {
        return hashFunction(data: data, depth: depth) * cipherSimulation(data: data, depth: depth + 1)
    }
}

func main() {
    let data = "secret"
    let depth = 1
    let result = cipherSimulation(data: data, depth: depth)
    print(result)
}

main()