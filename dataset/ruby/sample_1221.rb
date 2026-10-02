require 'digest'
require 'securerandom'

def data_mutations
  x = SecureRandom.random_bytes(16)
  h = Digest::SHA256.new
  h.update(x)
  y = h.digest
  z = SecureRandom.random_bytes(16)
  c = y.bytes.zip(z.bytes).map { |a, b| a ^ b }.pack('C*')
  return c
end

data_mutations