class StateMachine
  def initialize
    @state = 0
  end

  def transition
    if @state == 0
      @state = 1
    elsif @state == 1
      @state = 2
    elsif @state == 2
      @state = 0
    end
  end
end

def main
  sm = StateMachine.new
  loop do
    sm.transition
    puts sm.state
  end
end

main