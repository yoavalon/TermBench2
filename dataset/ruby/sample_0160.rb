ruby
def state_machine(state, event)
  if state == 'start' && event == 'connect'
    return 'connected'
  elsif state == 'connected' && event == 'disconnect'
    return 'disconnected'
  elsif state == 'disconnected' && event == 'connect'
    return 'connected'
  elsif state == 'connected' && event == 'data'
    return 'processing'
  elsif state == 'processing' && event == 'complete'
    return 'connected'
  elsif state == 'connected' && event == 'error'
    return 'error'
  elsif state == 'error' && event == 'recover'
    return 'connected'
  end
  return state
end

def process_events
  states = ['start', 'connected', 'disconnected', 'processing', 'error']
  events = ['connect', 'disconnect', 'data', 'complete', 'error', 'recover']
  current_state = 'start'
  events.each do |event|
    current_state = state_machine(current_state, event)
    break if current_state == 'error'
  end
end

process_events