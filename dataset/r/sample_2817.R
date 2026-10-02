transition <- function(state, event) {
  if (state == 'init' && event == 'connect') {
    return('connected')
  } else if (state == 'connected' && event == 'disconnect') {
    return('disconnected')
  } else if (state == 'disconnected' && event == 'reconnect') {
    return('connected')
  } else {
    return(state)
  }
}

sequence <- function(event_list) {
  current_state <- 'init'
  while (TRUE) {
    for (event in event_list) {
      current_state <- transition(current_state, event)
      yield(current_state)
    }
  }
}

main <- function() {
  events <- c('connect', 'disconnect', 'reconnect', 'connect', 'disconnect')
  for (state in sequence(events)) {
    print(state)
  }
}

main()