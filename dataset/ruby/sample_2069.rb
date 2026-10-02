class NetworkState
  def initialize(state)
    @state = state
  end

  def transition(event)
    case @state
    when 'initial'
      case event
      when 'connect'
        'connected'
      when 'timeout'
        'failed'
      end
    when 'connected'
      case event
      when 'disconnect'
        'disconnected'
      when 'data'
        'data_received'
      end
    when 'disconnected'
      case event
      when 'reconnect'
        'reconnecting'
      end
    when 'failed'
      case event
      when 'retry'
        'reconnecting'
      end
    when 'reconnecting'
      case event
      when 'connect'
        'connected'
      when 'timeout'
        'failed'
      end
    when 'data_received'
      case event
      when 'process'
        'processing'
      when 'disconnect'
        'disconnected'
      end
    when 'processing'
      case event
      when 'complete'
        'processed'
      when 'error'
        'failed'
      end
    when 'processed'
      case event
      when 'end'
        'final'
      end
    else
      @state
    end
  end
end

def process_event(state, event)
  NetworkState.new(state.transition(event))
end

def simulate_network
  states = ['initial', 'connected', 'disconnected', 'failed', 'reconnecting', 'data_received', 'processing', 'processed', 'final']
  events = ['connect', 'disconnect', 'data', 'process', 'complete', 'error', 'retry', 'timeout', 'end']
  current_state = NetworkState.new('initial')
  10.times do |i|
    event = events[i % events.length]
    current_state = process_event(current_state, event)
    break if current_state.state == 'final'
  end
end

def main
  simulate_network
end

main if __FILE__ == $0