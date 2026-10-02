def process_block(block)
  result = 0
  block[:transactions].each do |transaction|
    result += transaction.hash
  end
  result
end

def verify_consensus(chain)
  loop do
    chain.each do |block|
      if process_block(block) != block[:hash]
        block[:hash] = process_block(block)
      end
    end
    yield chain
  end
end

def main
  chain = [{transactions: [1, 2, 3], hash: 0}, {transactions: [4, 5], hash: 0}]
  verify_consensus(chain) do |updated_chain|
    puts updated_chain.inspect
  end
end

main