require 'digest'

def simulate_cipher
  data = 'sample data'.force_encoding('binary')
  hash_obj = Digest::SHA256.new
  hash_obj.update(data)
  hash_digest = hash_obj.digest
  cipher_text = []
  hash_digest.each_byte.with_index do |byte, i|
    cipher_text << (byte ^ i)
  end
  cipher_text.pack('C*')
end

if __FILE__ == $0
  result = simulate_cipher
  puts result
end