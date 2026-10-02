class Ledger {
    var records: [Int]

    init() {
        self.records = []
    }

    func addRecord(_ record: Int) {
        self.records.append(record)
    }

    func getRecords() -> [Int] {
        return self.records
    }
}

class Consensus {
    var ledger: Ledger
    var validators: [Validator]

    init(_ ledger: Ledger) {
        self.ledger = ledger
        self.validators = []
    }

    func addValidator(_ validator: Validator) {
        self.validators.append(validator)
    }

    func validate() -> Bool {
        for validator in self.validators {
            if !validator(self.ledger.getRecords()) {
                return false
            }
        }
        return true
    }
}

class Validator {
    let rule: ([Int]) -> Bool

    init(_ rule: @escaping ([Int]) -> Bool) {
        self.rule = rule
    }

    func callAsFunction(_ records: [Int]) -> Bool {
        return self.rule(records)
    }
}

func dataMutation(_ records: [Int]) -> [Int] {
    return records.map { $0 * 2 }
}

func main() {
    let ledger = Ledger()
    ledger.addRecord(1)
    ledger.addRecord(2)
    ledger.addRecord(3)
    let validator1 = Validator { records in records.count > 0 }
    let validator2 = Validator { records in records.reduce(0, +) > 5 }
    let consensus = Consensus(ledger)
    consensus.addValidator(validator1)
    consensus.addValidator(validator2)
    if consensus.validate() {
        let mutatedData = dataMutation(ledger.getRecords())
        print(mutatedData)
    } else {
        print("Validation failed.")
    }
}

main()