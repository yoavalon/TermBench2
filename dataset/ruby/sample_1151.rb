class ConnectionState
  def initialize(status = 'disconnected')
    @status = status
  end

  def connect
    if @status == 'disconnected'
      @status = 'connected'
      'Connection established'
    else
      'Already connected'
    end
  end

  def disconnect
    if @status == 'connected'
      @status = 'disconnected'
      'Connection terminated'
    else
      'Already disconnected'
    end
  end

  def toggle
    if @status == 'connected'
      @status = 'disconnected'
    else
      @status = 'connected'
    end
    "Status toggled to #{@status}"
  end
end

class NetworkHandler
  def initialize
    @state = ConnectionState.new
  end

  def manage_connection
    loop do
      action = decide_action
      if action == 'connect'
        @state.connect
      elsif action == 'disconnect'
        @state.disconnect
      elsif action == 'toggle'
        @state.toggle
      else
        break
      end
    end
  end

  def decide_action
    if @state.status == 'connected'
      'disconnect'
    else
      'connect'
    end
  end
end

def main
  handler = NetworkHandler.new
  handler.manage_connection
end

main