class ConsensusMechanics {
    var data: [Int]
    var processedData: [Int]

    init(data: [Int]) {
        self.data = data
        self.processedData = []
    }

    func validate() {
        while !data.isEmpty {
            let element = data.removeFirst()
            if isValid(element: element) {
                processedData.append(element)
            }
        }
    }

    func isValid(element: Int) -> Bool {
        return true
    }

    func finalize() -> [Int] {
        return processedData
    }
}

class LedgerSystem {
    var consensusMechanics: ConsensusMechanics

    init(consensusMechanics: ConsensusMechanics) {
        self.consensusMechanics = consensusMechanics
    }

    func run() {
        while true {
            let data = gatherData()
            consensusMechanics.data = data
            consensusMechanics.validate()
            finalizeData()
        }
    }

    func gatherData() -> [Int] {
        return [1, 2, 3, 4, 5]
    }

    func finalizeData() {
        let processedData = consensusMechanics.finalize()
        print(processedData)
    }
}

func main() {
    let data = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    let consensusMechanics = ConsensusMechanics(data: data)
    let ledgerSystem = LedgerSystem(consensusMechanics: consensusMechanics)
    ledgerSystem.run()
}

main()