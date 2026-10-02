require 'openssl'

def generate_hash(data)
  sha256 = OpenSSL::Digest::SHA256.new
  sha256.update(data)
  sha256.hexdigest
end

def simulate_cipher(hash_val)
  key = 'secret'
  cipher_text = []
  hash_val.scan(/../) do |byte_hex|
    byte = byte_hex.to_i(16) ^ key.bytes[i % key.bytesize]
    cipher_text << byte
  end
  cipher_text.pack('C*').unpack1('H*')
end

def main
  data = 'secure_message'
  hash_val = generate_hash(data)
  cipher_text = simulate_cipher(hash_val)
  puts cipher_text
end

main