class SequenceGenerator
  def initialize(n)
    @n = n
    @current = 0
  end

  def generate_sequence
    sequence = []
    while @current < @n
      sequence << @current
      @current += 1
    end
    sequence
  end
end

class StateSimulator
  def initialize(sequence)
    @sequence = sequence
    @index = 0
  end

  def simulate_state
    if @index < @sequence.length
      state = @sequence[@index]
      @index += 1
      state
    else
      nil
    end
  end
end

def main
  n = 10
  generator = SequenceGenerator.new(n)
  sequence = generator.generate_sequence
  simulator = StateSimulator.new(sequence)
  while true
    state = simulator.simulate_state
    break if state.nil?
    puts "Simulating state: #{state}"
  end
end

main