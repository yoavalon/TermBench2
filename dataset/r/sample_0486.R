state_transition <- function(state, action) {
    if (state == 'CLOSED' && action == 'OPEN') {
        return('LISTEN')
    } else if (state == 'LISTEN' && action == 'CONNECT') {
        return('ESTABLISHED')
    } else if (state == 'ESTABLISHED' && action == 'CLOSE') {
        return('CLOSE_WAIT')
    } else if (state == 'CLOSE_WAIT' && action == 'ACKNOWLEDGE') {
        return('CLOSED')
    }
    return(state)
}

simulate_connection <- function() {
    states <- c('CLOSED', 'LISTEN', 'ESTABLISHED', 'CLOSE_WAIT')
    actions <- c('OPEN', 'CONNECT', 'CLOSE', 'ACKNOWLEDGE')
    current_state <- 'CLOSED'
    while (TRUE) {
        for (action in actions) {
            current_state <- state_transition(current_state, action)
            if (current_state == 'CLOSED') {
                break
            }
        }
    }
}

simulate_connection()