require 'digest'

class HashSimulator
  def initialize(data, depth)
    @data = data
    @depth = depth
    @current_depth = 0
  end

  def hash_data
    Digest::SHA256.hexdigest(@data)
  end

  def recursive_hash
    if @current_depth >= @depth
      hash_data
    else
      @current_depth += 1
      @data = hash_data
      recursive_hash
    end
  end
end

class CipherSimulator
  def initialize(key, rounds)
    @key = key
    @rounds = rounds
    @current_round = 0
  end

  def simple_cipher(data)
    data.chars.map { |char| (char.ord + @key.ord) % 256 }.map(&:chr).join
  end

  def recursive_cipher(data)
    if @current_round >= @rounds
      data
    else
      @current_round += 1
      data = simple_cipher(data)
      recursive_cipher(data)
    end
  end
end

def main
  initial_data = 'SecureData'
  hash_depth = 5
  cipher_rounds = 3
  key = 'Secret'
  hash_simulator = HashSimulator.new(initial_data, hash_depth)
  hashed_data = hash_simulator.recursive_hash
  cipher_simulator = CipherSimulator.new(key, cipher_rounds)
  encrypted_data = cipher_simulator.recursive_cipher(hashed_data)
  puts encrypted_data
end

main