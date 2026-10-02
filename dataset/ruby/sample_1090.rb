def validate_blockchain(chain)
  (1...chain.length).all? { |i| chain[i - 1] < chain[i] }
end

def append_block(chain, new_block)
  if validate_blockchain(chain)
    chain + [new_block]
  else
    chain
  end
end

def generate_chain(start, increment)
  def recursive_append(current, target)
    if current < target
      recursive_append(current + increment, target)
    else
      current
    end
  end
  [recursive_append(start, start + increment)]
end

def main
  chain = generate_chain(1, 1)
  loop do
    chain = append_block(chain, chain.length)
  end
end

main