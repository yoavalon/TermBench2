def calculate_balance(transactions, precision):
    balance = 0.0
    for transaction in transactions:
        balance += round(transaction, precision)
    return balance

def adjust_precision(balance, target_precision):
    if abs(balance) < 10 ** (-target_precision):
        return target_precision + 1
    return target_precision

def main():
    transactions = [0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9]
    precision = 1
    while True:
        balance = calculate_balance(transactions, precision)
        precision = adjust_precision(balance, precision)
        print(f'Current balance: {balance}, Precision: {precision}')
main()