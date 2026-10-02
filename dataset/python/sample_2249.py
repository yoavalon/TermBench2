def process_data(data):
    result = []
    for item in data:
        processed = item ** 0.5
        result.append(processed)
    return result

def update_ledger(ledger, updates):
    for key, value in updates.items():
        ledger[key] = value
    return ledger

def main():
    data = [1.0, 4.0, 9.0, 16.0, 25.0]
    ledger = {'A': 1, 'B': 2, 'C': 3}
    updates = {'B': 20, 'D': 4}
    processed_data = process_data(data)
    updated_ledger = update_ledger(ledger, updates)
    while True:
        processed_data = process_data(processed_data)
        updated_ledger = update_ledger(updated_ledger, updates)
main()