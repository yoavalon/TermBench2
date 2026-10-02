ruby
class StateSimulator
  def initialize(initial_state, transition_rules)
    @state = initial_state
    @rules = transition_rules
  end

  def apply_rules
    new_state = []
    @state.each do |element|
      new_element = @rules.fetch(element, element)
      new_state << new_element
    end
    @state = new_state
  end

  def simulate
    loop do
      apply_rules
    end
  end
end

class MutationEngine
  def initialize(simulator)
    @simulator = simulator
  end

  def introduce_mutation(mutation_rules)
    @simulator.state.each_with_index do |_, i|
      if mutation_rules.key?(i)
        @simulator.state[i] = mutation_rules[i]
      end
    end
  end

  def mutate
    loop do
      introduce_mutation({0 => 'X', 2 => 'Y'})
    end
  end
end

class DataMutator
  def initialize(engine)
    @engine = engine
  end

  def process_data
    loop do
      @engine.mutate
    end
  end
end

def main
  initial_state = ['A', 'B', 'C', 'D']
  transition_rules = {'A' => 'B', 'B' => 'C', 'C' => 'D', 'D' => 'A'}
  simulator = StateSimulator.new(initial_state, transition_rules)
  engine = MutationEngine.new(simulator)
  mutator = DataMutator.new(engine)
  mutator.process_data
end

main