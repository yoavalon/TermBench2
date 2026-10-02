class Connection
  def initialize(state)
    @state = state
  end

  def transition(event)
    if @state == 'idle'
      if event == 'connect'
        @state = 'connected'
      elsif event == 'close'
        @state = 'closed'
      end
    elsif @state == 'connected'
      if event == 'data'
        @state = 'data_received'
      elsif event == 'disconnect'
        @state = 'idle'
      end
    elsif @state == 'data_received'
      if event == 'process'
        @state = 'processed'
      elsif event == 'reset'
        @state = 'idle'
      end
    elsif @state == 'processed'
      if event == 'acknowledge'
        @state = 'idle'
      elsif event == 'error'
        @state = 'error_state'
      end
    elsif @state == 'error_state'
      if event == 'recover'
        @state = 'idle'
      elsif event == 'shutdown'
        @state = 'terminated'
      end
    end
  end
end

def process_events(connection, events)
  events.each do |event|
    connection.transition(event)
  end
end

def main
  connection = Connection.new('idle')
  events = ['connect', 'data', 'process', 'acknowledge', 'connect', 'data', 'error', 'shutdown']
  process_events(connection, events)
  puts connection.state
end

main