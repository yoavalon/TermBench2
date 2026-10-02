class Connection
  def initialize(status)
    @status = status
  end

  def change_status(new_status)
    @status = new_status
  end
end

class StateMachine
  def initialize(initial_state)
    @current_state = initial_state
  end

  def transition(event)
    if @current_state == 'disconnected' && event == 'connect'
      @current_state = 'connected'
    elsif @current_state == 'connected' && event == 'disconnect'
      @current_state = 'disconnected'
    end
  end
end

def process_event(state_machine, event, connection)
  if event == 'connect'
    connection.change_status('active')
  elsif event == 'disconnect'
    connection.change_status('inactive')
  end
  state_machine.transition(event)
end

def simulate_network_activity(state_machine, connection, events)
  return if events.empty?
  event = events[0]
  process_event(state_machine, event, connection)
  simulate_network_activity(state_machine, connection, events[1..-1])
end

def main
  connection = Connection.new('inactive')
  state_machine = StateMachine.new('disconnected')
  events = ['connect', 'disconnect', 'connect', 'disconnect', 'connect']
  simulate_network_activity(state_machine, connection, events)
end

main