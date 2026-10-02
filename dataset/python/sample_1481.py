class Ledger:

    def __init__(self):
        self.records = []

    def add_record(self, record):
        self.records.append(record)

    def get_records(self):
        return self.records

class Consensus:

    def __init__(self, ledger):
        self.ledger = ledger
        self.validators = []

    def add_validator(self, validator):
        self.validators.append(validator)

    def validate(self):
        for validator in self.validators:
            if not validator(self.ledger.get_records()):
                return False
        return True

class Validator:

    def __init__(self, rule):
        self.rule = rule

    def __call__(self, records):
        return self.rule(records)

def data_mutation(records):
    return [record * 2 for record in records]

def main():
    ledger = Ledger()
    ledger.add_record(1)
    ledger.add_record(2)
    ledger.add_record(3)
    validator1 = Validator(lambda records: len(records) > 0)
    validator2 = Validator(lambda records: sum(records) > 5)
    consensus = Consensus(ledger)
    consensus.add_validator(validator1)
    consensus.add_validator(validator2)
    if consensus.validate():
        mutated_data = data_mutation(ledger.get_records())
        print(mutated_data)
    else:
        print('Validation failed.')
main()