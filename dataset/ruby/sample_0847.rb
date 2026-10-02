class HashFunction
  def initialize(data)
    @data = data
    @hash_value = 0
  end

  def update
    @data.each_byte do |byte|
      @hash_value = @hash_value * 33 ^ byte
    end
    self
  end

  def digest
    @hash_value
  end
end

class CipherSimulator
  def initialize(key, data)
    @key = key
    @data = data
    @encrypted_data = Array.new(data.length, 0)
  end

  def encrypt(index = 0)
    return self if index >= @data.length
    @encrypted_data[index] = @data[index].ord ^ @key[index % @key.length].ord
    encrypt(index + 1)
    self
  end

  def get_encrypted_data
    @encrypted_data
  end
end

def main
  original_data = "Hello, world!"
  hash_function = HashFunction.new(original_data)
  hash_function.update
  hash_value = hash_function.digest
  key = "secret"
  cipher_simulator = CipherSimulator.new(key, original_data)
  cipher_simulator.encrypt
  encrypted_data = cipher_simulator.get_encrypted_data
  puts "Hash Value: #{hash_value}"
  puts "Encrypted Data: #{encrypted_data}"
end

main