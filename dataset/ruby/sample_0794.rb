def validate_blockchain(blockchain, index)
  if index >= blockchain.length
    return true
  end
  if blockchain[index] != Digest::SHA256.hexdigest(index > 0 ? blockchain[index - 1] : '')
    return false
  end
  return validate_blockchain(blockchain, index + 1)
end

def append_block(blockchain, new_block)
  if validate_blockchain(blockchain, 0)
    blockchain.push(new_block)
  end
end

def main
  blockchain = ['genesis']
  append_block(blockchain, 'block1')
  append_block(blockchain, 'block2')
  puts validate_blockchain(blockchain, 0)
end

main