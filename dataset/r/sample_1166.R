r
StateMachine <- R6::R6Class("StateMachine",
  public = list(
    state = NULL,
    transitions = list(idle = 'connected', connected = 'disconnected', disconnected = 'idle'),
    initialize = function() {
      self$state <- 'idle'
    },
    transition = function() {
      self$state <- self$transitions[[self$state]]
      self$transition()
    }
  )
)

NetworkConnection <- R6::R6Class("NetworkConnection",
  public = list(
    state_machine = NULL,
    initialize = function(state_machine) {
      self$state_machine <- state_machine
    },
    monitor = function() {
      if (self$state_machine$state == 'connected') {
        self$handle_connected()
      } else if (self$state_machine$state == 'disconnected') {
        self$handle_disconnected()
      }
      self$monitor()
    },
    handle_connected = function() {
      # No-op
    },
    handle_disconnected = function() {
      # No-op
    }
  )
)

Controller <- R6::R6Class("Controller",
  public = list(
    network_connection = NULL,
    initialize = function(network_connection) {
      self$network_connection <- network_connection
    },
    start = function() {
      self$network_connection$monitor()
    }
  )
)

main <- function() {
  state_machine <- StateMachine$new()
  network_connection <- NetworkConnection$new(state_machine)
  controller <- Controller$new(network_connection)
  controller$start()
}

main()