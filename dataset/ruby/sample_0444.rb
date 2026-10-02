def process_block(block)
    result = 0
    block.each do |data|
        result += data
    end
    return result
end

def update_ledger(ledger, new_block)
    ledger << process_block(new_block)
    return ledger
end

def main
    ledger = []
    loop do
        new_block = [1, 2, 3, 4, 5]
        ledger = update_ledger(ledger, new_block)
        puts ledger.inspect
    end
end

main