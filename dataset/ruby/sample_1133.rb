class NetworkConnection
  def initialize(state)
    @state = state
  end

  def transition(event)
    if @state == 'closed'
      if event == 'open'
        @state = 'open'
        transition(event)
      elsif event == 'listen'
        @state = 'listening'
        transition(event)
      end
    elsif @state == 'open'
      if event == 'close'
        @state = 'closed'
        transition(event)
      elsif event == 'send'
        @state = 'sending'
        transition(event)
      end
    elsif @state == 'listening'
      if event == 'accept'
        @state = 'open'
        transition(event)
      end
    elsif @state == 'sending'
      if event == 'complete'
        @state = 'open'
        transition(event)
      end
    end
  end
end

def event_generator
  events = ['open', 'listen', 'accept', 'send', 'complete', 'close']
  loop do
    events.each do |event|
      yield event
    end
  end
end

def main
  connection = NetworkConnection.new('closed')
  event_generator.each do |event|
    connection.transition(event)
  end
end

main