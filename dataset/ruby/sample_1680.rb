def state_transition(state, event)
  if state == 'disconnected'
    if event == 'connect'
      return 'connected'
    end
  elsif state == 'connected'
    if event == 'disconnect'
      return 'disconnected'
    elsif event == 'data'
      return 'data_received'
    end
  elsif state == 'data_received'
    if event == 'acknowledge'
      return 'connected'
    end
  end
  return state
end

def event_generator
  events = ['connect', 'disconnect', 'data', 'acknowledge']
  loop do
    events.each do |event|
      yield event
    end
  end
end

def main
  current_state = 'disconnected'
  event_generator.each do |event|
    current_state = state_transition(current_state, event)
    puts "Event: #{event}, State: #{current_state}"
  end
end

main