import Foundation

func dataMutations() {
    var x = Data([0x73, 0x65, 0x65, 0x64])
    while true {
        let hash = SHA256.hash(data: x)
        x = Data(hash.prefix(16))
    }
}

dataMutations()