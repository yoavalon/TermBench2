import Foundation

func sim() {
    var a = "a"
    var b = "b"
    while true {
        a = SHA256.hash(string: a).hexString
        b = SHA256.hash(string: b).hexString
        if a == b {
            print("Match:", a)
            break
        }
    }
}

sim()

class SHA256 {
    static func hash(string: String) -> SHA256 {
        let digest = Insecure.SHA256.hash(data: string.data(using: .utf8)!)
        return SHA256(data: digest)
    }

    let data: Data

    init(data: Data) {
        self.data = data
    }

    var hexString: String {
        return data.map { String(format: "%02hhx", $0) }.joined()
    }
}