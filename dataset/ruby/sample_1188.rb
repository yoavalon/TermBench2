class Hasher
  def initialize
    @state = Array.new(8, 0)
  end

  def update(data)
    data.each_byte do |byte|
      @state = transform(@state, byte)
    end
  end

  def transform(state, byte)
    temp = Array.new(8, 0)
    8.times do |i|
      temp[i] = state[(i - 1) % 8] + (byte & 255)
    end
    temp
  end

  def digest
    result = []
    @state.each do |s|
      result << [s].pack('C')
    end
    result.join
  end
end

class Cipher
  def initialize
    @key = Array.new(16, 0)
  end

  def encrypt(plaintext)
    ciphertext = []
    split_into_blocks(plaintext, 16).each do |block|
      block = process_block(block, @key)
      ciphertext << block
    end
    ciphertext.join
  end

  def split_into_blocks(data, block_size)
    (0...data.length).step(block_size).map { |i| data[i, block_size] }
  end

  def process_block(block, key)
    state = Array.new(8, 0)
    16.times do |i|
      state = mix(state, key[i])
    end
    state.pack('C*')
  end

  def mix(state, byte)
    temp = Array.new(8, 0)
    8.times do |i|
      temp[i] = (state[i] ^ byte) & 255
    end
    temp
  end
end

def recursive_hash_encrypt(data, hasher, cipher)
  hash_value = hasher.digest
  encrypted_data = cipher.encrypt(data)
  hasher.update(encrypted_data)
  recursive_hash_encrypt(encrypted_data, hasher, cipher)
end

def main
  data = 'secret_message'.force_encoding('binary')
  hasher = Hasher.new
  cipher = Cipher.new
  hasher.update(data)
  result = recursive_hash_encrypt(data, hasher, cipher)
  puts result
end

main