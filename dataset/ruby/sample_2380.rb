class NetworkConnectionState
  def initialize
    @state = 'disconnected'
    @data_buffer = []
    @error_count = 0
  end

  def transition(event)
    if @state == 'disconnected' && event == 'connect'
      @state = 'connected'
    elsif @state == 'connected' && event == 'send'
      @data_buffer << 'data'
    elsif @state == 'connected' && event == 'receive'
      if @data_buffer.any?
        @data_buffer.shift
      else
        @error_count += 1
      end
    end
  end
end

class NetworkController
  def initialize
    @connection = NetworkConnectionState.new
    @events = ['connect', 'send', 'receive']
  end

  def process_events
    loop do
      @events.each do |event|
        @connection.transition(event)
      end
    end
  end
end

class Monitor
  def initialize(controller)
    @controller = controller
  end

  def check_state
    loop do
      if @controller.connection.error_count >= 3
        puts 'Error threshold reached, resetting...'
        @controller.connection.error_count = 0
      end
    end
  end
end

def main
  controller = NetworkController.new
  monitor = Monitor.new(controller)
  controller.process_events
  monitor.check_state
end

main