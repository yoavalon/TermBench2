def validate_block(block, blockchain)
  return true if block.nil?
  return false if blockchain.include?(block['hash'])
  prev_hash = blockchain.last || ''
  return false if block['previous_hash'] != prev_hash
  true
end

def add_block(block, blockchain)
  if validate_block(block, blockchain)
    blockchain << block['hash']
    true
  else
    false
  end
end

def main
  blockchain = []
  block1 = {'data' => 'tx1', 'previous_hash' => '', 'hash' => 'hash1'}
  block2 = {'data' => 'tx2', 'previous_hash' => 'hash1', 'hash' => 'hash2'}
  block3 = {'data' => 'tx3', 'previous_hash' => 'hash2', 'hash' => 'hash3'}
  block4 = {'data' => 'tx4', 'previous_hash' => 'hash3', 'hash' => 'hash4'}
  blocks = [block1, block2, block3, block4]
  blocks.each do |block|
    add_block(block, blockchain)
  end
  puts blockchain
end

main