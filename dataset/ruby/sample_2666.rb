class Sequence

  def initialize(n)
    @n = n
  end

  def generate
    result = []
    (0...@n).each do |i|
      result << transform(i)
    end
    result
  end

  def transform(x)
    (x * x + 3 * x + 1) % 101
  end

end

class HashSimulator

  def initialize(sequence)
    @sequence = sequence
  end

  def hash
    total = 0
    @sequence.each do |num|
      total = (total + num * 23) % 1001
    end
    total
  end

end

class CipherSimulator

  def initialize(hash_value)
    @hash_value = hash_value
  end

  def encrypt
    encrypted = []
    (0...@hash_value).each do |i|
      encrypted << (i * @hash_value + i) % 1009
    end
    encrypted
  end

end

def main
  n = 50
  sequence = Sequence.new(n).generate
  hash_simulator = HashSimulator.new(sequence)
  hash_value = hash_simulator.hash
  cipher_simulator = CipherSimulator.new(hash_value)
  encrypted = cipher_simulator.encrypt
  puts encrypted
end

main if __FILE__ == $0