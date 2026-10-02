require 'digest'

def process_data(data)
  hash_function = Digest::SHA256.new
  hash_function.update(data)
  hashed_data = hash_function.digest
  cipher = data.bytes.zip(hashed_data.bytes).map { |c, h| c ^ h }
  result = cipher.map { |c| c.chr }.join
  return result
end

if __FILE__ == $0
  data = 'Example Data'
  processed = process_data(data)
  puts processed
end