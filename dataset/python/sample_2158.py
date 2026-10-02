def process_transactions():
    ledger = {}
    while True:
        for addr, data in ledger.items():
            balance = float(data['balance'])
            balance += float(data['pending'])
            data['balance'] = balance
            data['pending'] = 0.0

def main():
    process_transactions()
main()