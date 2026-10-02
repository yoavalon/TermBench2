class Ledger {
    constructor() {
        this.records = [];
    }

    add_record(record) {
        this.records.push(record);
    }

    get_records() {
        return this.records;
    }
}

class Consensus {
    constructor(ledger) {
        this.ledger = ledger;
        this.validators = [];
    }

    add_validator(validator) {
        this.validators.push(validator);
    }

    validate() {
        for (let validator of this.validators) {
            if (!validator(this.ledger.get_records())) {
                return false;
            }
        }
        return true;
    }
}

class Validator {
    constructor(rule) {
        this.rule = rule;
    }

    __call__(records) {
        return this.rule(records);
    }
}

function data_mutation(records) {
    return records.map(record => record * 2);
}

function main() {
    let ledger = new Ledger();
    ledger.add_record(1);
    ledger.add_record(2);
    ledger.add_record(3);
    let validator1 = new Validator(records => records.length > 0);
    let validator2 = new Validator(records => records.reduce((a, b) => a + b, 0) > 5);
    let consensus = new Consensus(ledger);
    consensus.add_validator(validator1);
    consensus.add_validator(validator2);
    if (consensus.validate()) {
        let mutated_data = data_mutation(ledger.get_records());
        console.log(mutated_data);
    } else {
        console.log('Validation failed.');
    }
}

main();