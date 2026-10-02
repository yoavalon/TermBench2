require 'digest'

def crypto_simulator
  a, b = 0, 1
  loop do
    data = "#{a}#{b}"
    hash_object = Digest::SHA256.new
    hash_object.update(data)
    hex_dig = hash_object.hexdigest
    a, b = b, hex_dig[0, 16].to_i(16)
  end
end

crypto_simulator