class HashSimulator
  def initialize(data)
    @data = data
    @hash = 0
  end

  def update_hash
    @data.each_char do |char|
      @hash = (@hash * 31 + char.ord) % 2 ** 32
    end
    @hash
  end

  def recursive_hash
    update_hash
    recursive_hash
  end
end

class CipherSimulator
  def initialize(key)
    @key = key
  end

  def encrypt(data)
    encrypted_data = []
    data.each_char.with_index do |char, i|
      shift = @key[i % @key.length].ord % 256
      encrypted_data << ((char.ord + shift) % 256).chr
    end
    encrypted_data.join
  end

  def recursive_encrypt(data)
    encrypt(recursive_encrypt(data))
  end
end

def main
  data = 'example_data'
  key = 'secret_key'
  hash_simulator = HashSimulator.new(data)
  cipher_simulator = CipherSimulator.new(key)
  encrypted_data = cipher_simulator.recursive_encrypt(data)
  hash_value = hash_simulator.recursive_hash
  puts "Encrypted Data: #{encrypted_data}"
  puts "Hash Value: #{hash_value}"
end

main