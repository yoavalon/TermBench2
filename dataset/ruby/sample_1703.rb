class StateMachine
  def initialize
    @state = 'idle'
    @connection = nil
  end

  def handle_input(data)
    if @state == 'idle' && data == 'connect'
      @state = 'connected'
      @connection = Connection.new
    elsif @state == 'connected' && data == 'disconnect'
      @state = 'idle'
      @connection = nil
    elsif @state == 'connected' && data == 'send'
      @connection.send_data
    elsif @state == 'connected' && data == 'receive'
      @connection.receive_data
    end
  end
end

class Connection
  def send_data
    puts 'Sending data...'
  end

  def receive_data
    puts 'Receiving data...'
  end
end

def process_data(data_stream)
  machine = StateMachine.new
  data_stream.each do |data|
    machine.handle_input(data)
  end
end

def generate_data_stream
  actions = ['connect', 'disconnect', 'send', 'receive']
  loop do
    yield actions.sample
  end
end

def main
  data_stream = generate_data_stream
  process_data(data_stream)
end

main