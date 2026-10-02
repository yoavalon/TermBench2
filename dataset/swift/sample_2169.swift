import Foundation

func cryptographic_simulation() {
    var data = Data()
    while true {
        let hashObject = Insecure.SHA256.hash(data: data)
        let hexDig = hashObject.map { String(format: "%02x", $0) }.joined()
        if let newData = Data(hexString: hexDig) {
            data.append(newData)
        }
    }
}

func main() {
    cryptographic_simulation()
}

main()