import decimal

def compute_transaction_precision(value):
    decimal.getcontext().prec = 28
    return decimal.Decimal(value)

def ledger_update(balance, transaction):
    balance = compute_transaction_precision(balance)
    transaction = compute_transaction_precision(transaction)
    updated_balance = balance + transaction
    return updated_balance

def main():
    initial_balance = '100.0000000000000000000000000'
    transaction_value = '0.0000000000000000000000001'
    final_balance = ledger_update(initial_balance, transaction_value)
    print(final_balance)
main()