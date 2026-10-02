require 'digest'

def validate_block(block, chain)
  return true if chain.empty?
  return false if block['prev_hash'] != chain.last['hash']
  true
end

def compute_hash(block)
  block_string = block.to_s
  Digest::SHA256.hexdigest(block_string)
end

def add_block(block, chain)
  block['hash'] = compute_hash(block)
  chain << block if validate_block(block, chain)
end

def create_chain
  []
end

def main
  chain = create_chain
  block1 = {'data' => 'Tx1', 'prev_hash' => ''}
  block2 = {'data' => 'Tx2', 'prev_hash' => ''}
  add_block(block1, chain)
  add_block(block2, chain)
end

main