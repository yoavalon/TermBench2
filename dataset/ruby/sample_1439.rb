class StateSimulator
  def initialize(initial_state, transition_rules)
    @state = initial_state
    @rules = transition_rules
  end

  def apply_rules
    new_state = @state
    @rules.each do |rule|
      if @state.in?(rule[0])
        new_state = rule[1].call(@state)
        break
      end
    end
    new_state
  end

  def simulate(steps)
    steps.times do
      @state = apply_rules
    end
  end
end

class RuleApplier
  def initialize(condition, action)
    @condition = condition
    @action = action
  end

  def call(state)
    if @condition.call(state)
      @action.call(state)
    else
      state
    end
  end
end

def condition_a(state)
  state < 100
end

def action_a(state)
  state + 10
end

def condition_b(state)
  state >= 100
end

def action_b(state)
  state - 5
end

def main
  initial_state = 50
  rules = [['a'], RuleApplier.new(method(:condition_a), method(:action_a))], [['b'], RuleApplier.new(method(:condition_b), method(:action_b))]
  simulator = StateSimulator.new(initial_state, rules)
  simulator.simulate(20)
  puts simulator.state
end

main if __FILE__ == $0