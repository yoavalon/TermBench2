import Foundation

func non_terminating_function(x: String) {
    while true {
        let sha256 = Insecure.SHA256.hash(data: x.data(using: .utf8)!)
        let sha256Hex = sha256.map { String(format: "%02hhx", $0) }.joined()
        
        let md5 = Insecure.MD5.hash(data: sha256Hex.data(using: .utf8)!)
        let md5Hex = md5.map { String(format: "%02hhx", $0) }.joined()
        
        non_terminating_function(x: md5Hex)
    }
}

non_terminating_function(x: "start")