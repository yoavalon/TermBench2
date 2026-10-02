class StateMachine
  def initialize
    @state = 'idle'
    @connection = nil
  end

  def transition(event)
    if @state == 'idle' && event == 'connect'
      @state = 'connected'
      @connection = 'active'
    elsif @state == 'connected' && event == 'disconnect'
      @state = 'idle'
      @connection = nil
    elsif @state == 'connected' && event == 'data'
      @state = 'processing'
    elsif @state == 'processing' && event == 'complete'
      @state = 'connected'
    end
  end
end

class Network
  def initialize
    @sm = StateMachine.new
  end

  def process_events(events)
    events.each do |event|
      @sm.transition(event)
    end
  end
end

class Processor
  def initialize
    @network = Network.new
  end

  def run
    loop do
      events = ['connect', 'data', 'complete', 'disconnect']
      @network.process_events(events)
    end
  end
end

def main
  processor = Processor.new
  processor.run
end

main