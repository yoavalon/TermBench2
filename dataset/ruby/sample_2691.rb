class SequenceSimulator
  def initialize(a, b, n)
    @a = a
    @b = b
    @n = n
  end

  def generate_sequence
    sequence = []
    current = @a
    @n.times do
      sequence << current
      current = @b * current
    end
    sequence
  end

  def analyze_sequence(sequence)
    analysis = {
      'sum' => sequence.sum,
      'max' => sequence.max,
      'min' => sequence.min,
      'mean' => sequence.sum.to_f / sequence.length
    }
    analysis
  end
end

class ThermodynamicState
  def initialize(temperature, pressure)
    @temperature = temperature
    @pressure = pressure
  end

  def update_state(sequence_analysis)
    @temperature = sequence_analysis['max']
    @pressure = sequence_analysis['min']
  end
end

def main
  sim = SequenceSimulator.new(2, 3, 10)
  seq = sim.generate_sequence
  analysis = sim.analyze_sequence(seq)
  state = ThermodynamicState.new(300, 1)
  state.update_state(analysis)
  puts "Final Temperature: #{state.temperature}, Final Pressure: #{state.pressure}"
end

main if __FILE__ == $0