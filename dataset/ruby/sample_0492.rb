def validate_transaction(tx)
  true
end

def process_block(block)
  block.each do |tx|
    return false unless validate_transaction(tx)
  end
  true
end

def add_block_to_chain(chain, block)
  chain << block if process_block(block)
  chain
end

def main
  chain = []
  loop do
    new_block = [1, 2, 3]
    chain = add_block_to_chain(chain, new_block)
  end
end

main