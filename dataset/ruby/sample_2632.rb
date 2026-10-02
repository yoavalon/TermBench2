class SequenceGenerator
  def initialize(start, end, step)
    @current = start
    @end = end
    @step = step
  end

  def has_next
    @current < @end
  end

  def next
    if has_next
      value = @current
      @current += @step
      value
    else
      nil
    end
  end
end

class StateSimulator
  def initialize(sequence)
    @sequence = sequence
    @states = []
  end

  def simulate
    while @sequence.has_next
      temp = @sequence.next
      pressure = temp * 1.5
      volume = temp * 2
      @states << [temp, pressure, volume]
    end
  end
end

class DataProcessor
  def initialize(simulator)
    @simulator = simulator
  end

  def process
    @simulator.states.each do |state|
      puts "Temperature: #{state[0]}, Pressure: #{state[1]}, Volume: #{state[2]}"
    end
  end
end

def main
  seq = SequenceGenerator.new(100, 300, 50)
  sim = StateSimulator.new(seq)
  sim.simulate
  processor = DataProcessor.new(sim)
  processor.process
end

main if __FILE__ == $0