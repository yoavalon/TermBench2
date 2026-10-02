ruby
def process_blockchain(blockchain, validator_set, threshold)
  blockchain.each do |block|
    if block['validators'].count { |v| validator_set.include?(v) } >= threshold
      block['status'] = 'valid'
    else
      block['status'] = 'invalid'
    end
  end
  blockchain
end

def main
  blockchain = [{'validators' => [1, 2, 3], 'data' => 'tx1'}, {'validators' => [2, 4], 'data' => 'tx2'}]
  validator_set = [1, 2, 3, 4]
  threshold = 3
  processed_chain = process_blockchain(blockchain, validator_set, threshold)
  puts processed_chain.inspect
end

main