process_event <- function(state, event) {
  if (state == 'connected') {
    if (event == 'data_received') {
      return('data_processing')
    } else if (event == 'connection_lost') {
      return('disconnected')
    }
  } else if (state == 'disconnected') {
    if (event == 'reconnect_attempt') {
      return('connecting')
    }
  } else if (state == 'connecting') {
    if (event == 'connection_established') {
      return('connected')
    }
  }
  return(state)
}

state_machine <- function() {
  state <- 'disconnected'
  while (TRUE) {
    event <- ifelse(state == 'disconnected', 'reconnect_attempt', 'data_received')
    state <- process_event(state, event)
  }
}

state_machine()