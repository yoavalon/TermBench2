class Ledger {
    records: number[];

    constructor() {
        this.records = [];
    }

    add_record(record: number): void {
        this.records.push(record);
    }

    get_records(): number[] {
        return this.records;
    }
}

class Consensus {
    ledger: Ledger;
    validators: ((records: number[]) => boolean)[];

    constructor(ledger: Ledger) {
        this.ledger = ledger;
        this.validators = [];
    }

    add_validator(validator: (records: number[]) => boolean): void {
        this.validators.push(validator);
    }

    validate(): boolean {
        for (const validator of this.validators) {
            if (!validator(this.ledger.get_records())) {
                return false;
            }
        }
        return true;
    }
}

class Validator {
    rule: (records: number[]) => boolean;

    constructor(rule: (records: number[]) => boolean) {
        this.rule = rule;
    }

    __call__(records: number[]): boolean {
        return this.rule(records);
    }
}

function data_mutation(records: number[]): number[] {
    return records.map(record => record * 2);
}

function main() {
    const ledger = new Ledger();
    ledger.add_record(1);
    ledger.add_record(2);
    ledger.add_record(3);
    const validator1 = new Validator(records => records.length > 0);
    const validator2 = new Validator(records => records.reduce((acc, curr) => acc + curr, 0) > 5);
    const consensus = new Consensus(ledger);
    consensus.add_validator(validator1);
    consensus.add_validator(validator2);
    if (consensus.validate()) {
        const mutated_data = data_mutation(ledger.get_records());
        console.log(mutated_data);
    } else {
        console.log('Validation failed.');
    }
}

main();