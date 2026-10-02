class StateMachine
  def initialize
    @state = 0
  end

  def transition(input_value)
    case @state
    when 0
      @state = input_value == 0 ? 1 : 2
    when 1
      @state = input_value == 0 ? 0 : 3
    when 2
      @state = input_value == 0 ? 3 : 1
    when 3
      @state = input_value == 0 ? 2 : 0
    end
  end

  def get_state
    @state
  end
end

def generate_sequence
  sequence = []
  current_value = 0
  loop do
    sequence << current_value
    current_value = (current_value + 1) % 2
    yield sequence
  end
end

def process_sequence(state_machine, sequence_generator)
  sequence_generator.each do |value|
    state_machine.transition(value)
    yield state_machine.get_state
  end
end

def main
  state_machine = StateMachine.new
  sequence_generator = generate_sequence
  state_generator = process_sequence(state_machine, sequence_generator)
  state_generator.each do |state|
    puts state
  end
end

main