def state_transition(state, action)
    if state == 'CLOSED' and action == 'OPEN'
        'LISTEN'
    elsif state == 'LISTEN' and action == 'CONNECT'
        'ESTABLISHED'
    elsif state == 'ESTABLISHED' and action == 'CLOSE'
        'CLOSE_WAIT'
    elsif state == 'CLOSE_WAIT' and action == 'ACKNOWLEDGE'
        'CLOSED'
    else
        state
    end
end

def simulate_connection
    states = ['CLOSED', 'LISTEN', 'ESTABLISHED', 'CLOSE_WAIT']
    actions = ['OPEN', 'CONNECT', 'CLOSE', 'ACKNOWLEDGE']
    current_state = 'CLOSED'
    while true
        actions.each do |action|
            current_state = state_transition(current_state, action)
            if current_state == 'CLOSED'
                break
            end
        end
    end
end

simulate_connection