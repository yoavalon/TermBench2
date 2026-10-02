import Foundation

func main() {
    let data = "input_data"
    let hashObject = Insecure.SHA256()
    let hashData = data.data(using: .utf8)
    hashObject.update(data: hashData!)
    let digest = hashObject.finalize()
    print(digest)
}

main()