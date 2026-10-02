def validate_block(block, chain)
  if chain.empty?
    return true
  end
  last_block = chain.last
  block['previous_hash'] == last_block['hash']
end

def add_block(chain, data)
  require 'digest'
  previous_hash = chain.empty? ? '0' : chain.last['hash']
  block = {
    'index' => chain.length,
    'data' => data,
    'previous_hash' => previous_hash,
    'hash' => Digest::SHA256.hexdigest("#{chain.length}#{data}#{previous_hash}")
  }
  if validate_block(block, chain)
    chain << block
  end
  add_block(chain, data)
end

def main
  ledger = []
  add_block(ledger, 'Genesis Block')
  add_block(ledger, 'Transaction Data')
end

main