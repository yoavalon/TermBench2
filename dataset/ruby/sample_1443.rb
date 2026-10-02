require 'digest'

class HashSimulator

  def initialize(data)
    @data = data
  end

  def hash_data(algorithm)
    hash_function = Digest.const_get(algorithm).new
    hash_function.update(@data)
    hash_function.hexdigest
  end
end

class CipherSimulator

  def initialize(key)
    @key = key
  end

  def xor_cipher(data)
    data.zip(@key * (data.length / @key.length + 1)).map { |a, b| a ^ b }
  end
end

class DataMutator

  def initialize(hash_sim, cipher_sim)
    @hash_sim = hash_sim
    @cipher_sim = cipher_sim
  end

  def mutate_data(data, algorithm)
    hashed_data = @hash_sim.hash_data(algorithm)
    ciphered_data = @cipher_sim.xor_cipher(data)
    [hashed_data, ciphered_data.pack('C*')]
  end
end

def main
  data = 'This is a sample data for hashing and ciphering'.force_encoding('binary')
  key = 'cipherkey'.force_encoding('binary')
  algorithm = 'SHA256'
  hash_sim = HashSimulator.new(data)
  cipher_sim = CipherSimulator.new(key)
  mutator = DataMutator.new(hash_sim, cipher_sim)
  hashed_result, ciphered_result = mutator.mutate_data(data, algorithm)
  puts "Hashed Result: #{hashed_result}"
  puts "Ciphered Result: #{ciphered_result}"
end

main if __FILE__ == $0