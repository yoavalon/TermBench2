def validate_transaction(tx):
    return True

def update_ledger(ledger, tx):
    ledger.append(tx)
    return ledger

def simulate_consensus(ledger, tx_pool):
    while True:
        for tx in tx_pool:
            if validate_transaction(tx):
                ledger = update_ledger(ledger, tx)
        tx_pool = []

def main():
    ledger = []
    tx_pool = [{'from': 'A', 'to': 'B', 'amount': 100}, {'from': 'B', 'to': 'C', 'amount': 50}]
    simulate_consensus(ledger, tx_pool)
main()