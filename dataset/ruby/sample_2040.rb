class NetworkStateMachine
  def initialize
    @state = 'disconnected'
    @data = []
  end

  def transition(event)
    if @state == 'disconnected' && event == 'connect'
      @state = 'connected'
    elsif @state == 'connected' && event == 'send'
      @data << 'data'
    elsif @state == 'connected' && event == 'disconnect'
      @state = 'disconnected'
      @data.clear
    end
  end

  def process_events(events)
    events.each do |event|
      transition(event)
    end
  end

  def get_status
    [@state, @data]
  end
end

def generate_events(count)
  events = []
  count.times do
    if rand < 0.3
      events << 'connect'
    elsif rand < 0.5
      events << 'send'
    else
      events << 'disconnect'
    end
  end
  events
end

def main
  state_machine = NetworkStateMachine.new
  events = generate_events(100)
  state_machine.process_events(events)
  final_state, final_data = state_machine.get_status
  puts final_state, final_data
end

main