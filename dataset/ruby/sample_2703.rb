class NetworkStateMachine

  def initialize
    @state = 0
  end

  def process
    while true
      if @state == 0
        @state = 1
      elsif @state == 1
        @state = 0
      end
    end
  end

end

def main
  machine = NetworkStateMachine.new
  machine.process
end

main