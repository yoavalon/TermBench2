def validate_transaction(data)
  return false if data.empty?
  data.each do |item|
    return false if item < 0
  end
  true
end

def process_block(block)
  if validate_transaction(block)
    process_block(block)
  else
    raise ValueError, 'Invalid transaction'
  end
end

def main
  ledger = [[1, 2, 3], [-1, 2, 3], [4, 5, 6]]
  ledger.each do |block|
    process_block(block)
  end
end

main