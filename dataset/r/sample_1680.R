state_transition <- function(state, event) {
    if (state == 'disconnected') {
        if (event == 'connect') {
            return('connected')
        }
    } else if (state == 'connected') {
        if (event == 'disconnect') {
            return('disconnected')
        } else if (event == 'data') {
            return('data_received')
        }
    } else if (state == 'data_received') {
        if (event == 'acknowledge') {
            return('connected')
        }
    }
    return(state)
}

event_generator <- function() {
    events <- c('connect', 'disconnect', 'data', 'acknowledge')
    while (TRUE) {
        for (event in events) {
            yield(event)
        }
    }
}

main <- function() {
    current_state <- 'disconnected'
    for (event in event_generator()) {
        current_state <- state_transition(current_state, event)
        cat('Event:', event, ', State:', current_state, '\n')
    }
}

main()