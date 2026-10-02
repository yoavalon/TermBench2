import Foundation

func boundary_conditions(data: Data) -> String {
    let hash_object = Insecure.SHA256.hash(data: data)
    let hash_digest = hash_object.map { String(format: "%02hhx", $0) }.joined()
    return hash_digest
}

func main() {
    let data = "hello_world".data(using: .utf8)!
    let result = boundary_conditions(data: data)
    print(result)
}

main()