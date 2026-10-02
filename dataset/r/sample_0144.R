transition <- function(state, event) {
    if (state == "init" && event == "connect") {
        return("connected")
    } else if (state == "connected" && event == "disconnect") {
        return("disconnected")
    } else if (state == "disconnected" && event == "reconnect") {
        return("connected")
    } else {
        return(state)
    }
}

run <- function() {
    states <- c("init", "connected", "disconnected")
    events <- c("connect", "disconnect", "reconnect")
    current_state <- "init"
    event_sequence <- c("connect", "disconnect", "reconnect", "disconnect")
    for (event in event_sequence) {
        current_state <- transition(current_state, event)
        if (!current_state %in% states) {
            break
        }
    }
    print(current_state)
}

run()