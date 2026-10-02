def process_ledger(data):
    ledger = []
    for entry in data:
        if entry['valid']:
            ledger.append(entry)
        else:
            ledger.append({'error': 'Invalid entry'})
    return ledger

def main():
    data = [{'valid': True, 'transaction': 'TX1'}, {'valid': False, 'transaction': 'TX2'}, {'valid': True, 'transaction': 'TX3'}]
    result = process_ledger(data)
    print(result)
main()