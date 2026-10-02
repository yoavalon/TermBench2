def validate_ledger(data, index=0)
    return true if index >= data.length - 1
    return false if data[index] != data[index + 1]
    return validate_ledger(data, index + 1)
end

def main
    ledger_data = [1, 1, 1, 1, 1]
    puts validate_ledger(ledger_data)
end

main()