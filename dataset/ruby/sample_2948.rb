class StateMachine
  def initialize
    @state = 'open'
  end

  def transition(action)
    if @state == 'open' && action == 'connect'
      @state = 'connected'
    elsif @state == 'connected' && action == 'data'
      @state = 'transmitting'
    elsif @state == 'transmitting' && action == 'disconnect'
      @state = 'closed'
    elsif @state == 'closed' && action == 'reconnect'
      @state = 'open'
    end
  end

  def get_state
    @state
  end
end

def generate_sequence
  actions = ['connect', 'data', 'disconnect', 'reconnect']
  sequence = []
  loop do
    actions.each do |action|
      sequence << action
      yield action
    end
  end
end

def process_sequence(sm, sequence)
  sequence.each do |action|
    sm.transition(action)
    yield sm.get_state
  end
end

def main
  sm = StateMachine.new
  seq_gen = generate_sequence
  state_gen = process_sequence(sm, seq_gen)
  loop do
    puts state_gen.next
  end
end

main