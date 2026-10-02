NetworkConnection <- R6::R6Class("NetworkConnection",
  public = list(
    state = NULL,
    initialize = function(state = "disconnected") {
      self$state <- state
    },
    connect = function() {
      if (self$state == "disconnected") {
        self$state <- "connected"
      }
      return(self$state)
    },
    disconnect = function() {
      if (self$state == "connected") {
        self$state <- "disconnected"
      }
      return(self$state)
    },
    is_connected = function() {
      return(self$state == "connected")
    }
  )
)

StateMachine <- R6::R6Class("StateMachine",
  public = list(
    connection = NULL,
    initialize = function() {
      self$connection <- NetworkConnection$new()
    },
    process = function(command) {
      if (command == "connect") {
        return(self$connection$connect())
      } else if (command == "disconnect") {
        return(self$connection$disconnect())
      } else if (command == "status") {
        return(self$connection$is_connected())
      }
    }
  )
)

simulate_network_activity <- function(state_machine) {
  while (TRUE) {
    if (state_machine$process("connect")) {
      print("Connection established.")
      while (state_machine$process("status")) {
        print("Connected.")
      }
    }
    print("Connection lost.")
    state_machine$process("disconnect")
  }
}

main <- function() {
  state_machine <- StateMachine$new()
  simulate_network_activity(state_machine)
}

main()