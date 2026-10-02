class StateMachine

  def initialize
    @state = 'idle'
    @connection = nil
  end

  def transition(event)
    if @state == 'idle' && event == 'connect'
      @state = 'connected'
      @connection = true
    elsif @state == 'connected' && event == 'disconnect'
      @state = 'idle'
      @connection = false
    elsif @state == 'connected' && event == 'error'
      @state = 'error'
      @connection = false
    elsif @state == 'error' && event == 'recover'
      @state = 'connected'
      @connection = true
    end
  end

  def get_status
    [@state, @connection]
  end
end

def simulate_events(events)
  machine = StateMachine.new
  statuses = []
  events.each do |event|
    machine.transition(event)
    statuses << machine.get_status
  end
  statuses
end

def main
  events_sequence = ['connect', 'data', 'disconnect', 'connect', 'error', 'recover']
  results = simulate_events(events_sequence)
  results.each do |status|
    puts status
  end
end

main