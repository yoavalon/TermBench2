class HashSimulator

  def initialize(data)
    @data = data
  end

  def hash_function(value, iterations)
    if iterations == 0
      value
    else
      hash_function(cipher_function(value), iterations - 1)
    end
  end

  def cipher_function(value)
    new_value = 0
    value.each_char do |char|
      new_value += char.ord
    end
    new_value.to_s
  end

end

class CipherSimulator

  def initialize(data)
    @data = data
  end

  def cipher_function(value)
    new_value = ''
    value.each_char do |char|
      new_value << (char.ord + 1).chr
    end
    new_value
  end

end

class RecursiveSimulator

  def initialize(data, iterations)
    @data = data
    @iterations = iterations
  end

  def run_simulation
    hash_simulator = HashSimulator.new(@data)
    cipher_simulator = CipherSimulator.new(@data)
    @data = cipher_simulator.cipher_function(@data)
    @data = hash_simulator.hash_function(@data, @iterations)
    run_simulation
  end

end

def main
  initial_data = 'start'
  iterations = 10
  simulator = RecursiveSimulator.new(initial_data, iterations)
  simulator.run_simulation
end

main