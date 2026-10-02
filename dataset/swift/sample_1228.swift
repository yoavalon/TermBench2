import Foundation

func main() {
    let x = "hello"
    let h = Insecure.SHA256()
    h.update(data: x.data(using: .utf8)!)
    let y = h.finalize().map { String(format: "%02hhx", $0) }.joined()
    let z = String(y.reversed())
    print(z)
}

main()