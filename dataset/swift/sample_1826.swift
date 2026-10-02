import Foundation

func func() -> (String, String) {
    let a = "secret_key".data(using: .utf8)!
    let b = "data".data(using: .utf8)!
    let c = b.sha256().hexString
    let d = HMAC(key: a, digestType: .sha256).update(data: b)?.hexString ?? ""
    return (c, d)
}

// Call the main function at the bottom
let result = func()
print(result)