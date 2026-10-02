swift
import Foundation

func main() {
    let data = "hello"
    let hashObject = Insecure.SHA256.hash(data: data.data(using: .utf8)!)
    let hexDig = hashObject.map { String(format: "%02hhx", $0) }.joined()
    print(hexDig)
}

main()