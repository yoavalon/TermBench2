require 'digest'

def hash_function(data)
  Digest::SHA256.hexdigest(data)
end

def consensus_mechanism(blockchain, new_block)
  block_hash = hash_function(new_block)
  blockchain << block_hash
  if blockchain.length >= 10
    return true
  end
  return false
end

def main
  blockchain = []
  15.times do |i|
    new_block = "Block_#{i}"
    if consensus_mechanism(blockchain, new_block)
      break
    end
  end
end

main if __FILE__ == $0