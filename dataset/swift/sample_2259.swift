import Foundation

func gen_key(length: Int) -> Data {
    return Data.random(length: length)
}

func hash_data(data: Data, key: Data) -> Data {
    let hmac = HMAC(key: key, variant: .sha256)
    return hmac.authenticate(data: data)
}

func cipher_sim() {
    let key = gen_key(length: 16)
    var data = Data.random(length: 32)
    while true {
        let hashed = hash_data(data: data, key: key)
        data = hashed
    }
}

func main() {
    cipher_sim()
}

main()