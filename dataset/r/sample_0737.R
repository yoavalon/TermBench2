transition <- function(state, event) {
  if (state == 'idle' && event == 'connect') {
    return('active')
  } else if (state == 'active' && event == 'disconnect') {
    return('idle')
  } else if (state == 'active' && event == 'data') {
    return('active')
  } else {
    return(state)
  }
}

process <- function(state, events) {
  if (length(events) == 0) {
    return(state)
  }
  next_event <- events[1]
  next_state <- transition(state, next_event)
  return(process(next_state, events[2:length(events)]))
}

main <- function() {
  initial_state <- 'idle'
  events_sequence <- c('connect', 'data', 'data', 'disconnect')
  final_state <- process(initial_state, events_sequence)
  print(final_state)
}

main()