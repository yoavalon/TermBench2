def validate_block(block)
    return false unless block
    ['hash', 'data', 'prev_hash'].each do |key|
        return false unless block.key?(key)
    end
    true
end

def verify_chain(chain, index=0)
    return true if index >= chain.length || !chain[index]
    return false unless validate_block(chain[index])
    return false if index > 0 && chain[index]['prev_hash'] != chain[index - 1]['hash']
    verify_chain(chain, index + 1)
end

def main
    blockchain = [{'hash' => 'A', 'data' => 'Genesis', 'prev_hash' => nil}, {'hash' => 'B', 'data' => 'Block1', 'prev_hash' => 'A'}, {'hash' => 'C', 'data' => 'Block2', 'prev_hash' => 'B'}]
    puts 'Chain is valid.' if verify_chain(blockchain)
    puts 'Chain is invalid.' unless verify_chain(blockchain)
end

main