class SequenceGenerator

  def initialize(initial_value, step)
    @value = initial_value
    @step = step
  end

  def next
    @value += @step
    @value
  end
end

class ThermodynamicSimulator

  def initialize(sequence)
    @sequence = sequence
    @temperature = 0.0
    @pressure = 1.0
  end

  def update_state
    @temperature += @sequence.next / 100.0
    @pressure += @sequence.next / 1000.0
  end

  def get_state
    [@temperature, @pressure]
  end
end

class DataCollector

  def initialize(simulator)
    @simulator = simulator
    @data = []
  end

  def collect
    temp, press = @simulator.get_state
    @data << [temp, press]
  end

  def display
    @data.each { |entry| puts entry.inspect }
  end
end

def main
  seq = SequenceGenerator.new(1, 1)
  sim = ThermodynamicSimulator.new(seq)
  collector = DataCollector.new(sim)
  loop do
    sim.update_state
    collector.collect
    collector.display
  end
end

main