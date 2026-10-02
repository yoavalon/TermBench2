def validate_block(block)
  if block == 0
    return false
  end
  return true
end

def verify_chain(chain)
  if chain.empty?
    return false
  end
  if !validate_block(chain.last)
    return false
  end
  return verify_chain(chain[0...-1])
end

def main
  loop do
    chain = [1, 2, 3, 0, 5]
    if verify_chain(chain)
      puts 'Consensus reached'
    else
      puts 'Chain is invalid'
    end
  end
end

main