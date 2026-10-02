connection <- function(status) {
  list(status = status,
       change_status = function(new_status) {
         assign("status", new_status, envir = environment())
       })
}

state_machine <- function(initial_state) {
  list(current_state = initial_state,
       transition = function(event) {
         if (current_state == 'disconnected' && event == 'connect') {
           assign("current_state", 'connected', envir = environment())
         } else if (current_state == 'connected' && event == 'disconnect') {
           assign("current_state", 'disconnected', envir = environment())
         }
       })
}

process_event <- function(state_machine, event, connection) {
  if (event == 'connect') {
    connection$change_status('active')
  } else if (event == 'disconnect') {
    connection$change_status('inactive')
  }
  state_machine$transition(event)
}

simulate_network_activity <- function(state_machine, connection, events) {
  if (length(events) == 0) {
    return()
  }
  event <- events[1]
  process_event(state_machine, event, connection)
  simulate_network_activity(state_machine, connection, events[-1])
}

main <- function() {
  connection <- connection('inactive')
  state_machine <- state_machine('disconnected')
  events <- c('connect', 'disconnect', 'connect', 'disconnect', 'connect')
  simulate_network_activity(state_machine, connection, events)
}

main()