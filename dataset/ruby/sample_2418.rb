def main
  require 'digest'
  data = 'hello'
  hash_object = Digest::SHA256.new
  hex_dig = hash_object.hexdigest(data)
  puts hex_dig
end

main