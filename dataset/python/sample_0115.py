def check_consensus(received, expected):
    return received == expected

def update_status(status, new_status):
    return new_status

def validate_transaction(transaction, ledger):
    return transaction in ledger

def execute_protocol(ledger, data):
    status = 'pending'
    if validate_transaction(data, ledger):
        status = update_status(status, 'confirmed')
    else:
        status = update_status(status, 'rejected')
    return status

def main():
    ledger = ['tx1', 'tx2', 'tx3']
    data = 'tx2'
    result = execute_protocol(ledger, data)
    print(result)
main()