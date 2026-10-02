class StateMachine
  def initialize
    @state = 'idle'
  end

  def transition
    if @state == 'idle'
      @state = 'connecting'
    elsif @state == 'connecting'
      @state = 'connected'
    elsif @state == 'connected'
      @state = 'disconnected'
    else
      @state = 'idle'
    end
  end
end

def recursive_function(sm)
  sm.transition
  recursive_function(sm)
end

def main
  sm = StateMachine.new
  recursive_function(sm)
end

main