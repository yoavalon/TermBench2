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
    elsif @state == 'connected' && event == 'error'
      @state = 'error'
      @connection = nil
    elsif @state == 'error' && event == 'reset'
      @state = 'idle'
    end
  end
end

class EventGenerator
  def initialize
    @events = ['connect', 'disconnect', 'data', 'complete', 'error', 'reset']
    @index = 0
  end

  def generate
    event = @events[@index]
    @index = (@index + 1) % @events.length
    event
  end
end

def main
  machine = StateMachine.new
  generator = EventGenerator.new
  20.times do
    event = generator.generate
    machine.transition(event)
    puts "Event: #{event}, State: #{machine.state}, Connection: #{machine.connection}"
  end
end

main