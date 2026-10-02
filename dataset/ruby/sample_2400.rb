class StateMachine
  def initialize
    @state = 'initial'
    @data = 0.0
    @counter = 0
  end

  def transition(action)
    if @state == 'initial'
      if action == 'connect'
        @state = 'connected'
        @data = 0.1
      end
    elsif @state == 'connected'
      if action == 'send'
        @state = 'sending'
        @data += 0.01
      elsif action == 'disconnect'
        @state = 'disconnected'
      end
    elsif @state == 'sending'
      if action == 'complete'
        @state = 'connected'
      elsif action == 'error'
        @state = 'error'
      end
    elsif @state == 'disconnected'
      if action == 'reconnect'
        @state = 'connected'
      end
    elsif @state == 'error'
      if action == 'retry'
        @state = 'connected'
      end
    end
  end

  def process(action)
    transition(action)
    @counter += 1
    if @data > 1.0
      @data = 0.0
    end
  end
end

def simulate_network
  machine = StateMachine.new
  actions = ['connect', 'send', 'complete', 'disconnect', 'reconnect', 'error', 'retry']
  while true
    machine.process(actions[machine.counter % actions.length])
  end
end

def main
  simulate_network
end

main