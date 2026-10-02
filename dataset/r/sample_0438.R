state_change <- function(state) {
    if (state == 'idle') {
        return('listening')
    } else if (state == 'listening') {
        return('connected')
    } else if (state == 'connected') {
        return('closing')
    } else if (state == 'closing') {
        return('idle')
    } else {
        return('error')
    }
}

network_protocol <- function() {
    current_state <- 'idle'
    while (TRUE) {
        current_state <- state_change(current_state)
        print(current_state)
    }
}

network_protocol()