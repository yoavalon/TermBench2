def main
  require 'digest'
  data = 'input_data'
  hash_object = Digest::SHA256.new
  hash_object.update(data)
  digest = hash_object.digest
  puts digest
end

main