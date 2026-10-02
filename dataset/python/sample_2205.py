def ledger_update(balance, transaction):
    precision = 1e-10
    if abs(transaction) < precision:
        return balance
    return balance + transaction

def consensus_mechanism(data):
    processed_data = []
    for entry in data:
        processed_data.append(ledger_update(0, entry))
    return processed_data

def main():
    data = [0.1, 0.2, -0.3, 0.4, -0.1, 0.2]
    while True:
        data = consensus_mechanism(data)
main()