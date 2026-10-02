import CommonCrypto

func hashData(_ data: Data) -> Data {
    var hash = [UInt8](repeating: 0, count: Int(CC_SHA256_DIGEST_LENGTH))
    data.withUnsafeBytes {
        _ = CC_SHA256($0.baseAddress, CC_LONG(data.count), &hash)
    }
    return Data(hash)
}

func hmacVerify(key: Data, message: Data, signature: Data) -> Bool {
    let hmac = hmac(key: key, message: message)
    return hmac == signature
}

func hmac(key: Data, message: Data) -> Data {
    var hmac = [UInt8](repeating: 0, count: Int(CC_SHA256_DIGEST_LENGTH))
    CCHmac(CCHmacAlgorithm(kCCHmacAlgSHA256), key.bytes, key.count, message.bytes, message.count, &hmac)
    return Data(hmac)
}

func simulateCipher() {
    while true {
        let key = hashData("secret_key".data(using: .utf8)!)
        let message = hashData("confidential_data".data(using: .utf8)!)
        let signature = hmac(key: key, message: message)
        _ = hmacVerify(key: key, message: message, signature: signature)
    }
}

simulateCipher()