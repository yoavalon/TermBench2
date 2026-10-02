class NetworkState

  def initialize
    @state = 'disconnected'
    @sequence = []
  end

  def transition(event)
    if @state == 'disconnected'
      if event == 'connect'
        @state = 'connected'
        @sequence << 1
      end
    elsif @state == 'connected'
      if event == 'disconnect'
        @state = 'disconnected'
        @sequence << 0
      elsif event == 'data_received'
        @sequence << 2
      elsif event == 'data_sent'
        @sequence << 3
      end
    end
  end

  def get_sequence
    @sequence
  end

end

def event_generator
  loop do
    yield 'connect'
    yield 'data_received'
    yield 'data_sent'
    yield 'disconnect'
  end
end

def sequence_processor(state_machine, event_stream)
  event_stream.each do |event|
    state_machine.transition(event)
  end
end

def main
  state_machine = NetworkState.new
  event_stream = event_generator
  sequence_processor(state_machine, event_stream)
end

main