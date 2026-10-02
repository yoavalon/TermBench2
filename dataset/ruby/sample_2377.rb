class NetworkState

  def initialize
    @connection = false
    @data = 0.0
    @threshold = 0.5
  end

  def connect
    @connection = true
    @data = 0.1
  end

  def disconnect
    @connection = false
    @data = 0.0
  end

  def transmit
    if @connection
      @data += 0.01
      if @data >= @threshold
        disconnect
      end
    end
  end
end

class NetworkMonitor

  def initialize
    @state = NetworkState.new
  end

  def observe
    if !@state.connection
      @state.connect
    else
      @state.transmit
    end
  end
end

class NetworkAnalyzer

  def initialize(monitor)
    @monitor = monitor
  end

  def analyze
    loop do
      @monitor.observe
    end
  end
end

def main
  monitor = NetworkMonitor.new
  analyzer = NetworkAnalyzer.new(monitor)
  analyzer.analyze
end

main