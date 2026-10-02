class StateMachine
  def initialize
    @state = 'idle'
  end

  def transition(event)
    if @state == 'idle'
      if event == 'connect'
        @state = 'active'
      elsif event == 'error'
        @state = 'errored'
      end
    elsif @state == 'active'
      if event == 'disconnect'
        @state = 'idle'
      elsif event == 'error'
        @state = 'errored'
      end
    elsif @state == 'errored'
      if event == 'recover'
        @state = 'idle'
      end
    end
  end

  def process(event_sequence)
    event_sequence.each do |event|
      transition(event)
      yield @state
    end
  end
end

def generate_events
  loop do
    yield 'connect'
    yield 'disconnect'
    yield 'error'
    yield 'recover'
  end
end

def monitor(state_machine, event_generator)
  event_generator.each do |event|
    state_machine.transition(event)
    puts "Event: #{event}, State: #{state_machine.state}"
  end
end

def main
  state_machine = StateMachine.new
  event_generator = generate_events
  monitor(state_machine, event_generator)
end

main