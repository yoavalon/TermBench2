def hash_data(data)
  result = 0
  data.each_byte do |byte|
    result = (result * 31 + byte) & 18446744073709551615
  end
  result
end

def simulate_cipher(data)
  key = 25214903917
  mask = 18446744073709551615
  state = hash_data(data)
  encrypted = []
  data.length.times do
    state = (state * key + 11) & mask
    encrypted << (state >> 16) & 255
  end
  encrypted
end

def main
  data = 'Sample data for cryptographic operations'.force_encoding('BINARY')
  encrypted_data = simulate_cipher(data)
  puts encrypted_data.pack('C*')
end

main