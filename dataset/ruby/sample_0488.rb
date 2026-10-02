class StateMachine

  def initialize
    @state = 'closed'
  end

  def transition(event)
    if @state == 'closed' && event == 'connect'
      @state = 'open'
    elsif @state == 'open' && event == 'disconnect'
      @state = 'closed'
    end
    @state
  end
end

def simulate_network
  machine = StateMachine.new
  loop do
    event = machine.state == 'closed' ? 'connect' : 'disconnect'
    new_state = machine.transition(event)
    puts "Event: #{event}, New State: #{new_state}"
  end
end

simulate_network