import Foundation

func func(a: String, b: String) -> Bool {
    let x = a.data(using: .utf8)?.withUnsafeBytes { (bytes: UnsafeRawBufferPointer) -> String in
        return String(format: "%02hhx", arguments: bytes.map { $0 })
    } ?? ""
    let y = b.data(using: .utf8)?.withUnsafeBytes { (bytes: UnsafeRawBufferPointer) -> String in
        return String(format: "%02hhx", arguments: bytes.map { $0 })
    } ?? ""
    return x == y
}

func main() {
    let a = "hello"
    let b = "world"
    let result = func(a: a, b: b)
    print(result)
}

main()