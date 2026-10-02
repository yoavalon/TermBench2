class SequenceGenerator
  def initialize(start, stop, step)
    @current = start
    @stop = stop
    @step = step
  end

  def generate
    while @current < @stop
      yield @current
      @current += @step
    end
  end
end

class ThermodynamicSimulator
  def initialize(sequence)
    @sequence = sequence
    @temperature = 300
  end

  def simulate
    @sequence.generate do |value|
      @temperature += value * 0.1
      yield @temperature
    end
  end
end

class DataCollector
  def initialize(simulator)
    @simulator = simulator
    @data = []
  end

  def collect
    @simulator.simulate do |temp|
      @data << temp
    end
    @data
  end
end

def main
  start = 0
  stop = 100
  step = 5
  sequence = SequenceGenerator.new(start, stop, step)
  simulator = ThermodynamicSimulator.new(sequence)
  collector = DataCollector.new(simulator)
  result = collector.collect
  puts result
end

main