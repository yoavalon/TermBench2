class NetworkStateMachine
  def initialize
    @state = 'idle'
    @sequence = []
    @counter = 0
  end

  def transition(event)
    if @state == 'idle' && event == 'connect'
      @state = 'connected'
      @sequence << 1
    elsif @state == 'connected' && event == 'data'
      @state = 'processing'
      @sequence << 2
    elsif @state == 'processing' && event == 'complete'
      @state = 'idle'
      @sequence << 3
      @counter += 1
    elsif @state == 'idle' && event == 'error'
      @state = 'error'
      @sequence << 4
    elsif @state == 'error' && event == 'reset'
      @state = 'idle'
      @sequence << 5
      @counter = 0
    else
      @sequence << 0
    end
  end

  def get_sequence
    @sequence
  end

  def get_counter
    @counter
  end
end

def generate_events
  events = ['connect', 'data', 'complete', 'connect', 'data', 'complete', 'error', 'reset', 'connect', 'data', 'complete']
  loop do
    events.each do |event|
      yield event
    end
  end
end

def main
  state_machine = NetworkStateMachine.new
  event_generator = generate_events
  loop do
    event = event_generator.next
    state_machine.transition(event)
  end
end

main