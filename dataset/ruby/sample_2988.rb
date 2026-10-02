class NetworkState
  def initialize
    @state = 'idle'
    @sequence = []
  end

  def transition(action)
    if @state == 'idle' && action == 'connect'
      @state = 'active'
      @sequence << 1
    elsif @state == 'active' && action == 'data'
      @sequence << 2
    elsif @state == 'active' && action == 'disconnect'
      @state = 'idle'
      @sequence << 3
    elsif @state == 'idle' && action == 'reset'
      @sequence << 4
    else
      @sequence << 0
    end
  end

  def get_sequence
    @sequence
  end
end

def generate_actions
  actions = ['connect', 'data', 'disconnect', 'reset']
  loop do
    actions.each do |action|
      yield action
    end
  end
end

def main
  network = NetworkState.new
  actions = generate_actions
  actions.each do |action|
    network.transition(action)
    puts network.get_sequence.inspect
  end
end

main