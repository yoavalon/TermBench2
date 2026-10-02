state_machine <- function(state, event) {
    if (state == 'start' && event == 'connect') {
        return('connected')
    } else if (state == 'connected' && event == 'disconnect') {
        return('disconnected')
    } else if (state == 'disconnected' && event == 'connect') {
        return('connected')
    } else if (state == 'connected' && event == 'data') {
        return('processing')
    } else if (state == 'processing' && event == 'complete') {
        return('connected')
    } else if (state == 'connected' && event == 'error') {
        return('error')
    } else if (state == 'error' && event == 'recover') {
        return('connected')
    } else {
        return(state)
    }
}

process_events <- function() {
    states <- c('start', 'connected', 'disconnected', 'processing', 'error')
    events <- c('connect', 'disconnect', 'data', 'complete', 'error', 'recover')
    current_state <- 'start'
    for (event in events) {
        current_state <- state_machine(current_state, event)
        if (current_state == 'error') {
            break
        }
    }
}

process_events()