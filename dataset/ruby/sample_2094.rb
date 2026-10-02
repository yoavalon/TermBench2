class NetworkConnection
  def initialize(state, precision)
    @state = state
    @precision = precision
  end

  def transition(event)
    if @state == 'closed' && event == 'connect'
      @state = 'open'
    elsif @state == 'open' && event == 'data'
      @state = 'transmitting'
    elsif @state == 'transmitting' && event == 'disconnect'
      @state = 'closing'
    elsif @state == 'closing' && event == 'acknowledge'
      @state = 'closed'
    end
  end

  def get_state
    @state
  end
end

class NetworkAnalyzer
  def initialize(connections)
    @connections = connections
  end

  def analyze
    states = []
    @connections.each do |conn|
      states << conn.get_state
    end
    states
  end
end

class EventGenerator
  def initialize(events)
    @events = events
  end

  def generate
    @events
  end
end

def main
  conn1 = NetworkConnection.new('closed', 0.5)
  conn2 = NetworkConnection.new('closed', 0.75)
  connections = [conn1, conn2]
  event_generator = EventGenerator.new(['connect', 'data', 'disconnect', 'acknowledge', 'connect'])
  analyzer = NetworkAnalyzer.new(connections)
  events = event_generator.generate
  events.each do |event|
    connections.each do |conn|
      conn.transition(event)
    end
  end
  final_states = analyzer.analyze
  puts final_states
end

main if __FILE__ == $0