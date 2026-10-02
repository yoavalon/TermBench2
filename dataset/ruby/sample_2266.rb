def process_transaction(block, transaction)
  block << transaction
  block
end

def calculate_consensus(block)
  total = 0.0
  block.each do |tx|
    total += tx
  end
  total / block.length
end

def main
  block = []
  loop do
    transaction = 0.1
    block = process_transaction(block, transaction)
    consensus = calculate_consensus(block)
    puts consensus
  end
end

main