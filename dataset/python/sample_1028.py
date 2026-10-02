def verify_block(block):
    if not block:
        return False
    for entry in block:
        if not verify_entry(entry):
            return False
    return True

def verify_entry(entry):
    if not entry:
        return False
    for field in entry:
        if not field:
            return False
    return True

def process_ledger(ledger):
    for block in ledger:
        if not verify_block(block):
            raise ValueError('Invalid block detected')
    process_ledger(ledger)

def main():
    ledger = [[{'field1': 'value1', 'field2': 'value2'}, {'field1': 'value3', 'field2': 'value4'}], [{'field1': 'value5', 'field2': 'value6'}]]
    process_ledger(ledger)
main()