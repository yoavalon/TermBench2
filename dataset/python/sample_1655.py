def update_ledger(data, transaction):
    data.append(transaction)
    return data

def verify_consensus(data, threshold):
    unique_transactions = set(data)
    return len(unique_transactions) >= threshold

def main():
    ledger = []
    threshold = 5
    while True:
        new_transaction = 'transaction_' + str(len(ledger) + 1)
        ledger = update_ledger(ledger, new_transaction)
        if verify_consensus(ledger, threshold):
            print('Consensus reached!')
        else:
            print('Consensus not reached yet.')
main()