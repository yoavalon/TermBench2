class NetworkStateMachine

  def initialize
    @state = 0
    @sequence = [0, 1, 1, 2, 3, 5, 8, 13, 21, 34]
  end

  def transition(data)
    if data < 0
      @state = 1
    elsif data > 0
      @state = 2
    else
      @state = 0
    end
  end

  def process(data)
    transition(data)
    @sequence[@state]
  end

end

def main
  machine = NetworkStateMachine.new
  result = machine.process(-5)
  puts result
end

main