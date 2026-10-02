require 'digest'

def hash_data(data)
  sha256 = Digest::SHA256.new
  sha256.update(data)
  sha256.hexdigest
end

def encrypt_block(block, key)
  encrypted_block = []
  block.each_with_index do |byte, i|
    encrypted_byte = (byte + key[i % key.length]) % 256
    encrypted_block << encrypted_byte
  end
  encrypted_block.pack('C*')
end

def simulate_cipher(data, key)
  block_size = 16
  num_blocks = (data.length + block_size - 1) / block_size
  encrypted_data = []
  (0...num_blocks).each do |i|
    block_start = i * block_size
    block_end = [block_start + block_size, data.length].min
    block = data[block_start...block_end]
    encrypted_block = encrypt_block(block, key)
    encrypted_data << encrypted_block
  end
  encrypted_data.join
end

def main
  data = 'Hello, World!'.force_encoding('ASCII-8BIT')
  key = 'secret_key'.force_encoding('ASCII-8BIT')
  hashed_data = hash_data(data)
  encrypted_data = simulate_cipher(data, key)
  puts 'Hashed Data:', hashed_data
  puts 'Encrypted Data:', [encrypted_data].pack('H*').unpack1('H*')
end

main