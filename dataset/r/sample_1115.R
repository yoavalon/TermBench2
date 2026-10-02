StateMachine <- R6::R6Class("StateMachine",
  public = list(
    state = NULL,
    initialize = function(state) {
      self$state <- state
    },
    transition = function(event) {
      if (self$state == 'open') {
        if (event == 'data') {
          self$state <- 'data_received'
        } else if (event == 'close') {
          self$state <- 'closed'
        }
      } else if (self$state == 'data_received') {
        if (event == 'ack') {
          self$state <- 'acknowledged'
        } else if (event == 'error') {
          self$state <- 'error'
        }
      } else if (self$state == 'acknowledged') {
        if (event == 'data') {
          self$state <- 'data_received'
        } else if (event == 'close') {
          self$state <- 'closed'
        }
      } else if (self$state == 'error') {
        if (event == 'reset') {
          self$state <- 'open'
        } else if (event == 'close') {
          self$state <- 'closed'
        }
      }
    }
  )
)

event_generator <- function() {
  events <- c('data', 'data', 'ack', 'data', 'error', 'reset', 'data', 'close')
  repeat {
    for (event in events) {
      yield(event)
    }
  }
}

simulate_network_connection <- function() {
  state_machine <- StateMachine$new('open')
  event_stream <- event_generator()
  for (event in event_stream) {
    state_machine$transition(event)
    cat('Event:', event, ', State:', state_machine$state, '\n')
  }
}

main <- function() {
  simulate_network_connection()
}

main()