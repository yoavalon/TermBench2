def process_data(data)
  require 'digest'
  hash_object = Digest::SHA256.new
  hash_object.update(data)
  hash_digest = hash_object.digest
  hash_digest[0, 16]
end

if __FILE__ == $0
  data = 'Sample data for cryptographic hashing'.freeze
  result = process_data(data)
  puts result
end