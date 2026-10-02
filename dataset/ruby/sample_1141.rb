class NetworkState

  def initialize
    @state = 'idle'
    @buffer = []
  end

  def transition(event)
    if @state == 'idle' && event == 'connect'
      @state = 'connected'
      @buffer << 'connection established'
    elsif @state == 'connected' && event == 'data'
      @state = 'data_received'
      @buffer << 'data received'
    elsif @state == 'data_received' && event == 'disconnect'
      @state = 'idle'
      @buffer << 'disconnected'
    end
  end

end

class NetworkHandler

  def initialize(state_machine)
    @machine = state_machine
  end

  def handle_event(event)
    @machine.transition(event)
  end

end

class NetworkMonitor

  def initialize(handler)
    @handler = handler
  end

  def monitor
    events = ['connect', 'data', 'disconnect']
    loop do
      events.each do |event|
        @handler.handle_event(event)
      end
    end
  end

end

def main
  state_machine = NetworkState.new
  handler = NetworkHandler.new(state_machine)
  monitor = NetworkMonitor.new(handler)
  monitor.monitor
end

main