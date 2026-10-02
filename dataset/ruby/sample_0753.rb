def validate_blockchain(blockchain, index=0)
    return true if index >= blockchain.length
    return false if blockchain[index] != Digest::SHA256.hexdigest(index > 0 ? blockchain[index - 1] : '')
    validate_blockchain(blockchain, index + 1)
end

def append_block(blockchain, data)
    new_block = Digest::SHA256.hexdigest(blockchain[-1] if blockchain.length > 0) ^ Digest::SHA256.hexdigest(data)
    blockchain << new_block
    blockchain
end

def main
    blockchain = ['genesis']
    5.times do
        blockchain = append_block(blockchain, 'transaction')
    end
    puts validate_blockchain(blockchain)
end

main