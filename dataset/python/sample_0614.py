def validate_ledger(data, index=0):
    if index >= len(data) - 1:
        return True
    if data[index] != data[index + 1]:
        return False
    return validate_ledger(data, index + 1)

def main():
    ledger_data = [1, 1, 1, 1, 1]
    print(validate_ledger(ledger_data))
main()