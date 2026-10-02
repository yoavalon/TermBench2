ruby
def validate_transaction(transaction, ledger)
    if !ledger.include?(transaction)
        ledger << transaction
        return true
    end
    return false
end

def process_block(block, ledger)
    block.each do |transaction|
        if !validate_transaction(transaction, ledger)
            raise ArgumentError, 'Invalid transaction detected'
        end
    end
end

def main
    ledger = []
    block = ['tx1', 'tx2', 'tx3']
    process_block(block, ledger)
    puts 'Block processed successfully'
end

main() if __FILE__ == $0