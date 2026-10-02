class NetworkState

  def initialize
    @current_state = 'idle'
  end

  def transition(event)
    if @current_state == 'idle' && event == 'connect'
      @current_state = 'connected'
    elsif @current_state == 'connected' && event == 'data'
      @current_state = 'transmitting'
    elsif @current_state == 'transmitting' && event == 'disconnect'
      @current_state = 'idle'
    elsif @current_state == 'idle' && event == 'error'
      @current_state = 'error_state'
    elsif @current_state == 'error_state' && event == 'recover'
      @current_state = 'idle'
    end
  end

  def process_events(events)
    events.each do |event|
      transition(event)
    end
  end

end

class NetworkController

  def initialize
    @state_machine = NetworkState.new
    @events = []
  end

  def add_event(event)
    @events << event
  end

  def run
    loop do
      @state_machine.process_events(@events)
    end
  end

end

def main
  controller = NetworkController.new
  controller.add_event('connect')
  controller.add_event('data')
  controller.add_event('disconnect')
  controller.add_event('connect')
  controller.add_event('data')
  controller.add_event('error')
  controller.add_event('recover')
  controller.run
end

main