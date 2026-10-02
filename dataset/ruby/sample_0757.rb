require 'digest'

def validate_block(block, chain)
  return true if chain.empty?
  last_block = chain.last
  return true if block['prev_hash'] == last_block['hash']
  return false
end

def add_block(block, chain)
  return true if validate_block(block, chain)
  chain << block
  return true
  return false
end

def create_block(prev_hash, data)
  block = {'index' => prev_hash.length + 1, 'prev_hash' => prev_hash, 'data' => data}
  block['hash'] = Digest::SHA256.hexdigest(block.to_s)
  return block
end

def main
  chain = []
  genesis_block = create_block('', 'Genesis')
  add_block(genesis_block, chain)
  new_block = create_block(genesis_block['hash'], 'Transaction 1')
  add_block(new_block, chain)
  puts chain
end

main