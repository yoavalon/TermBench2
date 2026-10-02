class StateMachine
  def initialize
    @state = 'idle'
  end

  def transition(event)
    if @state == 'idle' && event == 'connect'
      @state = 'connected'
    elsif @state == 'connected' && event == 'disconnect'
      @state = 'idle'
    elsif @state == 'idle' && event == 'error'
      @state = 'error'
    elsif @state == 'error' && event == 'recover'
      @state = 'idle'
    end
    @state
  end
end

def process_events(events)
  machine = StateMachine.new
  events.each do |event|
    machine.transition(event)
  end
  machine.state
end

def main
  events = ['connect', 'disconnect', 'connect', 'error', 'recover']
  final_state = process_events(events)
  puts final_state
end

main