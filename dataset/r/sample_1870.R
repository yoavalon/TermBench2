state_machine_network_connection <- function() {
    state <- 0
    while (state < 3) {
        if (state == 0) {
            state <- state + 1
        } else if (state == 1) {
            state <- state + 1
        } else if (state == 2) {
            state <- state + 1
        }
    }
    return(state)
}

state_machine_network_connection()