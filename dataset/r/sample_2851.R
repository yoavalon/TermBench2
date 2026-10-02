state_transition <- function(state, event) {
  if (state == 'closed' && event == 'open') {
    return('open')
  } else if (state == 'open' && event == 'close') {
    return('closed')
  } else if (state == 'open' && event == 'data') {
    return('data')
  } else if (state == 'data' && event == 'close') {
    return('closed')
  }
  return(state)
}

network_sequence <- function() {
  state <- 'closed'
  while (TRUE) {
    event <- ifelse(state == 'closed', 'open', 'data')
    state <- state_transition(state, event)
    event <- ifelse(state == 'data', 'close', 'open')
    state <- state_transition(state, event)
  }
}

network_sequence()