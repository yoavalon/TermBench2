class NetworkState
  def initialize
    @connection = 0
    @state = 'disconnected'
  end

  def connect
    @connection = 1
    @state = 'connected'
  end

  def disconnect
    @connection = 0
    @state = 'disconnected'
  end

  def is_connected
    @state == 'connected'
  end
end

class DataProcessor
  def initialize(network)
    @network = network
    @data = 0.0
  end

  def process_data(value)
    if @network.is_connected
      @data += value
    else
      raise 'Network is disconnected'
    end
  end
end

class Monitor
  def initialize(processor)
    @processor = processor
    @threshold = 100.0
  end

  def check_threshold
    if @processor.data >= @threshold
      @processor.data = 0.0
      @processor.network.disconnect
      raise 'Threshold exceeded and connection closed'
    end
  end
end

def main
  network = NetworkState.new
  processor = DataProcessor.new(network)
  monitor = Monitor.new(processor)
  network.connect
  while true
    begin
      processor.process_data(10.0)
      monitor.check_threshold
    rescue Exception => e
      puts e
    end
  end
end

main