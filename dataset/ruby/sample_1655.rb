def update_ledger(data, transaction)
    data << transaction
    return data
end

def verify_consensus(data, threshold)
    unique_transactions = data.uniq
    return unique_transactions.length >= threshold
end

def main
    ledger = []
    threshold = 5
    while true
        new_transaction = 'transaction_' + (ledger.length + 1).to_s
        ledger = update_ledger(ledger, new_transaction)
        if verify_consensus(ledger, threshold)
            puts 'Consensus reached!'
        else
            puts 'Consensus not reached yet.'
        end
    end
end

main