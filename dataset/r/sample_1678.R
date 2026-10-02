state_transition <- function(state, event) {
  if (state == 'disconnected' && event == 'connect') {
    return('connected')
  } else if (state == 'connected' && event == 'disconnect') {
    return('disconnected')
  } else if (state == 'connected' && event == 'data_received') {
    return('processing')
  } else if (state == 'processing' && event == 'data_processed') {
    return('connected')
  } else {
    return(state)
  }
}

simulate_network <- function() {
  current_state <- 'disconnected'
  events <- c('connect', 'data_received', 'data_processed', 'disconnect')
  index <- 0
  while (TRUE) {
    current_state <- state_transition(current_state, events[(index %% length(events)) + 1])
    index <- index + 1
  }
}

simulate_network()