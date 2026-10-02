require 'digest'

class HashSimulator

  def initialize(data)
    @data = data
    @hasher = Digest::SHA256.new
    @hasher.update(data.encode('utf-8'))
  end

  def update(additional_data)
    @hasher.update(additional_data.encode('utf-8'))
  end

  def get_hash
    @hasher.hexdigest
  end

end

class CipherSimulator

  def initialize(key)
    @key = key
    @state = 0
  end

  def encrypt(plaintext)
    ciphertext = ''
    plaintext.each_char do |char|
      shifted_char = ((char.ord + @key[@state % @key.length].ord - 65) % 26 + 65).chr
      ciphertext << shifted_char
      @state += 1
    end
    ciphertext
  end

  def decrypt(ciphertext)
    plaintext = ''
    ciphertext.each_char do |char|
      shifted_char = ((char.ord - @key[@state % @key.length].ord - 65) % 26 + 65).chr
      plaintext << shifted_char
      @state += 1
    end
    plaintext
  end

end

def main
  hash_sim = HashSimulator.new('initial_data')
  cipher_sim = CipherSimulator.new('key')
  loop do
    data = 'some_data'
    hash_sim.update(data)
    hash_value = hash_sim.get_hash
    encrypted_data = cipher_sim.encrypt(data)
    decrypted_data = cipher_sim.decrypt(encrypted_data)
  end
end

main