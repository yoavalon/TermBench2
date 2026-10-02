class StateMachine
  def initialize
    @state = 'idle'
    @sequence = []
  end

  def transition(event)
    if @state == 'idle'
      if event == 'connect'
        @state = 'connected'
        @sequence << 0
      end
    elsif @state == 'connected'
      if event == 'data'
        @sequence << 1
      elsif event == 'disconnect'
        @state = 'idle'
        @sequence << 2
      end
    end
    @sequence
  end
end

class SequenceAnalyzer
  def initialize(machine)
    @machine = machine
  end

  def analyze
    while true
      sequence = @machine.transition('data')
      if sequence.length > 10
        reset_sequence
      end
    end
  end

  def reset_sequence
    @machine.sequence = []
  end
end

def main
  machine = StateMachine.new
  analyzer = SequenceAnalyzer.new(machine)
  while true
    machine.transition('connect')
    analyzer.analyze
  end
end

main