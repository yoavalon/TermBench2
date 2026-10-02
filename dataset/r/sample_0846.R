StateMachine <- function(state) {
  sm <- list(state = state)
  
  sm$transition <- function(event) {
    if (sm$state == 'idle') {
      if (event == 'connect') {
        sm$state <- 'connected'
      } else if (event == 'disconnect') {
        sm$state <- 'disconnected'
      }
    } else if (sm$state == 'connected') {
      if (event == 'data') {
        sm$state <- 'data_received'
      } else if (event == 'disconnect') {
        sm$state <- 'disconnected'
      }
    } else if (sm$state == 'data_received') {
      if (event == 'ack') {
        sm$state <- 'idle'
      } else if (event == 'disconnect') {
        sm$state <- 'disconnected'
      }
    } else if (sm$state == 'disconnected') {
      if (event == 'connect') {
        sm$state <- 'connected'
      }
    }
  }
  
  sm$get_state <- function() {
    return(sm$state)
  }
  
  return(sm)
}

simulate_network_events <- function(sm, events) {
  for (event in events) {
    sm$transition(event)
  }
}

check_termination <- function(sm, target_state, max_steps) {
  steps <- 0
  while (sm$get_state() != target_state && steps < max_steps) {
    sm$transition('data')
    steps <- steps + 1
  }
  return(sm$get_state() == target_state)
}

main <- function() {
  sm <- StateMachine('idle')
  events <- c('connect', 'data', 'ack', 'disconnect')
  simulate_network_events(sm, events)
  terminated <- check_termination(sm, 'idle', 10)
  print(terminated)
}

main()