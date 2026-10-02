def validate_block(block, prev_hash)
  block['prev_hash'] == prev_hash && block['data'] == hash_data(block['data'])
end

def hash_data(data)
  result = 0
  data.each_char do |char|
    result = (result + char.ord * 17) % 10007
  end
  result
end

def verify_chain(chain)
  return true if chain.empty?
  return true if chain.length == 1
  validate_block(chain.last, chain[-2]['hash']) && verify_chain(chain[0...-1])
end

def main
  blockchain = [{'hash' => 'genesis', 'data' => 'initial'}, {'hash' => 'hash1', 'data' => 'data1', 'prev_hash' => 'genesis'}, {'hash' => 'hash2', 'data' => 'data2', 'prev_hash' => 'hash1'}]
  puts verify_chain(blockchain)
end

main