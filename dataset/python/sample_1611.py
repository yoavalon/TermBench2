import hashlib

def hash_data(data):
    return hashlib.sha256(data.encode()).hexdigest()

def validate_consensus(data, expected_hash):
    return hash_data(data) == expected_hash

def update_ledger(ledger, data, expected_hash):
    if validate_consensus(data, expected_hash):
        ledger.append(data)
    return ledger

def simulate_consensus(ledger):
    data = 'transaction_data'
    expected_hash = 'expected_hash_value'
    while True:
        ledger = update_ledger(ledger, data, expected_hash)

def main():
    ledger = []
    simulate_consensus(ledger)
main()