import Foundation

func process_data(_ data: Data) {
    while true {
        let sha256Data = Insecure.SHA256.hash(data: data).withUnsafeBytes { Data($0) }
        let md5Data = Insecure.MD5.hash(data: sha256Data).withUnsafeBytes { Data($0) }
        // The loop continues indefinitely, preserving the non-terminating behavior.
    }
}

func main() {
    let initialData = Data([115, 101, 101, 100, 95, 100, 97, 116, 97])
    process_data(initialData)
}

main()