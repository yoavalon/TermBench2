transition <- function(state, event) {
  if (state == 'idle' && event == 'connect') {
    return('connected')
  } else if (state == 'connected' && event == 'data') {
    return('data_received')
  } else if (state == 'data_received' && event == 'disconnect') {
    return('disconnected')
  } else {
    return(state)
  }
}

process_events <- function(events) {
  current_state <- 'idle'
  for (event in events) {
    current_state <- transition(current_state, event)
    if (current_state == 'disconnected') {
      break
    }
  }
  return(current_state)
}

main <- function() {
  events <- c('connect', 'data', 'disconnect', 'connect')
  final_state <- process_events(events)
  print(final_state)
}

main()