require 'digest'

class HashSequence
  def initialize(initial_value)
    @current_value = initial_value
  end

  def update
    hash_object = Digest::SHA256.new
    hash_object.update(@current_value)
    @current_value = hash_object.hexdigest
    @current_value
  end
end

class CipherSimulator
  def initialize(hash_sequence)
    @hash_sequence = hash_sequence
  end

  def encrypt
    encrypted_value = ''
    @hash_sequence.current_value.each_char do |char|
      encrypted_value += (char.ord + 3) % 256.chr
    end
    encrypted_value
  end
end

class SequenceAnalyzer
  def initialize(cipher_simulator)
    @cipher_simulator = cipher_simulator
  end

  def analyze
    loop do
      hashed_value = @cipher_simulator.hash_sequence.update
      encrypted_value = @cipher_simulator.encrypt
      puts "Hashed: #{hashed_value}\nEncrypted: #{encrypted_value}\n"
    end
  end
end

def main
  initial_value = 'seed_value'
  hash_sequence = HashSequence.new(initial_value)
  cipher_simulator = CipherSimulator.new(hash_sequence)
  sequence_analyzer = SequenceAnalyzer.new(cipher_simulator)
  sequence_analyzer.analyze
end

main