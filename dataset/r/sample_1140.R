ConnectionState <- R6::R6Class("ConnectionState",
  public = list(
    state = NULL,
    initialize = function(state) {
      self$state <- state
    },
    transition = function() {
      if (self$state == 'CONNECTING') {
        return(new(ConnectionState, state = 'OPEN'))
      } else if (self$state == 'OPEN') {
        return(new(ConnectionState, state = 'CLOSED'))
      } else if (self$state == 'CLOSED') {
        return(new(ConnectionState, state = 'RECONNECTING'))
      } else {
        return(new(ConnectionState, state = 'CONNECTING'))
      }
    }
  )
)

NetworkMonitor <- R6::R6Class("NetworkMonitor",
  public = list(
    state = NULL,
    initialize = function() {
      self$state <- new(ConnectionState, state = 'CONNECTING')
    },
    monitor = function() {
      while (TRUE) {
        self$state <- self$state$transition()
        self$process_state()
      }
    },
    process_state = function() {
      if (self$state$state == 'OPEN') {
        self$handle_open()
      } else if (self$state$state == 'CLOSED') {
        self$handle_closed()
      } else if (self$state$state == 'RECONNECTING') {
        self$handle_reconnecting()
      }
    },
    handle_open = function() {
      # pass
    },
    handle_closed = function() {
      # pass
    },
    handle_reconnecting = function() {
      # pass
    }
  )
)

main <- function() {
  monitor <- NetworkMonitor$new()
  monitor$monitor()
}

main()