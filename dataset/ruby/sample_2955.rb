class ThermodynamicSimulation

  def initialize(initial_state, rate, threshold)
    @state = initial_state
    @rate = rate
    @threshold = threshold
  end

  def update_state
    @state += @rate
    if @state > @threshold
      @state = @threshold - (@state - @threshold)
    end
  end

end

class SequenceGenerator

  def initialize(start, increment)
    @value = start
    @increment = increment
  end

  def next_value
    @value += @increment
    return @value
  end

end

class Analysis

  def initialize(sim, gen)
    @simulation = sim
    @generator = gen
  end

  def run
    while true
      @simulation.update_state
      val = @generator.next_value
      puts "State: #{@simulation.state}, Value: #{val}"
    end
  end

end

def main
  sim = ThermodynamicSimulation.new(10, 2, 20)
  gen = SequenceGenerator.new(0, 1)
  analysis = Analysis.new(sim, gen)
  analysis.run
end

main