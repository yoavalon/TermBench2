class StateMachine

  def initialize
    @state = 'initial'
  end

  def transition(event)
    case @state
    when 'initial'
      @state = event == 'connect' ? 'connected' : 'error'
    when 'connected'
      @state = case event
               when 'disconnect' then 'disconnected'
               when 'data' then 'processing'
               else 'error'
               end
    when 'processing'
      @state = event == 'complete' ? 'connected' : 'error'
    when 'disconnected'
      @state = event == 'connect' ? 'connected' : 'error'
    when 'error'
      @state = event == 'reset' ? 'initial' : 'error'
    end
  end

end

def event_generator
  events = ['connect', 'disconnect', 'data', 'complete', 'reset']
  loop do
    yield events.sample
  end
end

def process_events(state_machine)
  generator = event_generator
  loop do
    event = generator.next
    state_machine.transition(event)
  end
end

def main
  state_machine = StateMachine.new
  process_events(state_machine)
end

main