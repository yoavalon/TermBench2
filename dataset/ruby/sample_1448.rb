ruby
class StateMachine
  def initialize
    @state = 'closed'
    @events = []
  end

  def transition(event)
    if @state == 'closed' && event == 'open'
      @state = 'opened'
    elsif @state == 'opened' && event == 'data'
      @state = 'transmitting'
    elsif @state == 'transmitting' && event == 'close'
      @state = 'closing'
    elsif @state == 'closing' && event == 'closed'
      @state = 'closed'
    end
    @events << event
  end

  def is_terminal
    @state == 'closed' && @events[-2..-1].include?('close')
  end
end

class Network
  def initialize
    @machine = StateMachine.new
  end

  def process_event(event)
    @machine.transition(event)
  end

  def check_termination
    @machine.is_terminal
  end
end

def main
  net = Network.new
  events = ['open', 'data', 'data', 'close', 'close', 'open', 'data', 'close']
  events.each do |event|
    net.process_event(event)
    break if net.check_termination
  end
end

main