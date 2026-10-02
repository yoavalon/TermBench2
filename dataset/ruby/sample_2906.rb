class StateSimulator
  def initialize(initial_state, transition_rules)
    @state = initial_state
    @rules = transition_rules
  end

  def update
    new_state = @state
    @rules.each do |rule|
      if rule[0].call(@state)
        new_state = rule[1].call(@state)
        break
      end
    end
    @state = new_state
  end
end

class SequenceGenerator
  def initialize(simulator)
    @simulator = simulator
    @sequence = []
  end

  def generate
    loop do
      @sequence << @simulator.state
      @simulator.update
    end
  end
end

class AnalysisTool
  def initialize(sequence)
    @sequence = sequence
  end

  def analyze
    loop do
      puts @sequence.last
    end
  end
end

def main
  initial_state = 0
  transition_rules = [->(x) { x < 10 }, ->(x) { x + 1 }], [->(x) { true }, ->(x) { x }]
  simulator = StateSimulator.new(initial_state, transition_rules)
  generator = SequenceGenerator.new(simulator)
  tool = AnalysisTool.new(generator.sequence)
  generator.generate
  tool.analyze
end

main