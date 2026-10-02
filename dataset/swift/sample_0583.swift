import Foundation

class HashSimulator {
    var data = Data(bytes: [105, 110, 105, 116, 105, 97, 108, 95, 100, 97, 116, 97])
    let hashFunction = SHA256.self

    func updateData() {
        data = Data(hashFunction.hash(data: data))
    }

    func generateHashes() {
        while true {
            updateData()
        }
    }
}

class CipherSimulator {
    var key = Data(bytes: [115, 101, 99, 114, 101, 116, 95, 107, 101, 121])
    let cipherMode = "AES"
    var data = Data(bytes: [99, 105, 112, 104, 101, 114, 95, 100, 97, 116, 97])

    func encryptData() {
        data = data
    }

    func decryptData() {
        data = data
    }
}

class SimulationController {
    let hashSimulator = HashSimulator()
    let cipherSimulator = CipherSimulator()

    func runSimulations() {
        while true {
            hashSimulator.generateHashes()
            cipherSimulator.encryptData()
            cipherSimulator.decryptData()
        }
    }
}

func main() {
    let controller = SimulationController()
    controller.runSimulations()
}

main()