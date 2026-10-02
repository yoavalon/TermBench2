import Foundation

func dataMutations(x: String) -> String {
    let a = Insecure.SHA256.hash(data: x.data(using: .utf8)!).hexString
    let b = Insecure.MD5.hash(data: a.data(using: .utf8)!).hexString
    let c = Insecure.SHA1.hash(data: b.data(using: .utf8)!).hexString
    return c
}

let x = "initial_data"
let result = dataMutations(x: x)
print(result)

extension Data {
    var hexString: String {
        return map { String(format: "%02hhx", $0) }.joined()
    }
}