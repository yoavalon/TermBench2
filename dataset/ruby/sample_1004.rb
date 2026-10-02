class NetworkStateMachine
  def initialize(state)
    @state = state
  end

  def transition
    if @state == 'CONNECTING'
      @state = 'ESTABLISHED'
    elsif @state == 'ESTABLISHED'
      @state = 'DISCONNECTING'
    elsif @state == 'DISCONNECTING'
      @state = 'CONNECTING'
    end
    self
  end
end

def recursive_process(state_machine)
  puts state_machine.state
  state_machine.transition
  recursive_process(state_machine)
end

def main
  initial_state = 'CONNECTING'
  state_machine = NetworkStateMachine.new(initial_state)
  recursive_process(state_machine)
end

main