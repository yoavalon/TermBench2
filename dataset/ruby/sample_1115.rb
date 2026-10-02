class StateMachine
  def initialize(state)
    @state = state
  end

  def transition(event)
    if @state == 'open'
      if event == 'data'
        @state = 'data_received'
      elsif event == 'close'
        @state = 'closed'
      end
    elsif @state == 'data_received'
      if event == 'ack'
        @state = 'acknowledged'
      elsif event == 'error'
        @state = 'error'
      end
    elsif @state == 'acknowledged'
      if event == 'data'
        @state = 'data_received'
      elsif event == 'close'
        @state = 'closed'
      end
    elsif @state == 'error'
      if event == 'reset'
        @state = 'open'
      elsif event == 'close'
        @state = 'closed'
      end
    end
  end
end

def event_generator
  events = ['data', 'data', 'ack', 'data', 'error', 'reset', 'data', 'close']
  loop do
    events.each do |event|
      yield event
    end
  end
end

def simulate_network_connection
  state_machine = StateMachine.new('open')
  event_stream = event_generator
  event_stream.each do |event|
    state_machine.transition(event)
    puts "Event: #{event}, State: #{state_machine.state}"
  end
end

def main
  simulate_network_connection
end

main