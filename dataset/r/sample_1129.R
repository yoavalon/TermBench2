NetworkState <- function(state) {
  list(
    state = state,
    transition = function(event) {
      if (state == 'DISCONNECTED' && event == 'CONNECT') {
        return('CONNECTED')
      } else if (state == 'CONNECTED' && event == 'DISCONNECT') {
        return('DISCONNECTED')
      } else if (state == 'CONNECTED' && event == 'RECEIVE') {
        return('PROCESSING')
      } else if (state == 'PROCESSING' && event == 'SEND') {
        return('CONNECTED')
      } else {
        return(state)
      }
    }
  )
}

NetworkStateMachine <- function() {
  list(
    current_state = NetworkState('DISCONNECTED'),
    process_event = function(event) {
      new_state <- current_state$transition(event)
      current_state <<- NetworkState(new_state)
      return(new_state)
    }
  )
}

generate_events <- function() {
  events <- c('CONNECT', 'RECEIVE', 'SEND', 'DISCONNECT')
  return(rep(events, 10))
}

simulate_network <- function() {
  state_machine <- NetworkStateMachine()
  events <- generate_events()
  index <- 0
  while (TRUE) {
    event <- events[(index %% length(events)) + 1]
    new_state <- state_machine$process_event(event)
    index <- index + 1
    if (new_state == 'PROCESSING') {
      simulate_network()
    }
  }
}

main <- function() {
  simulate_network()
}

main()