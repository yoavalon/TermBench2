def validate_block(block, prev_hash, current_hash)
    if !block || block['prev_hash'] != prev_hash
        return false
    end
    if current_hash != block['hash']
        return false
    end
    return true
end

def verify_chain(chain)
    if !chain
        return false
    end
    prev_hash = 'genesis_hash'
    chain.each do |block|
        if !validate_block(block, prev_hash, block['hash'])
            return false
        end
        prev_hash = block['hash']
    end
    return true
end

def main()
    blockchain = [{'hash' => 'block1_hash', 'prev_hash' => 'genesis_hash'}, {'hash' => 'block2_hash', 'prev_hash' => 'block1_hash'}, {'hash' => 'block3_hash', 'prev_hash' => 'block2_hash'}]
    puts verify_chain(blockchain)
end

main()