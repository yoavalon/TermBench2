NetworkState <- R6::R6Class("NetworkState",
  public = list(
    status = "disconnected",
    connection_attempts = 0,
    
    connect = function() {
      self$connection_attempts <- self$connection_attempts + 1
      if (self$connection_attempts < 5) {
        self$status <- "connecting"
        self$transition()
      } else {
        self$status <- "failed"
      }
    },
    
    transition = function() {
      if (self$status == "connecting") {
        self$status <- "connected"
      } else if (self$status == "connected") {
        self$status <- "disconnecting"
      } else if (self$status == "disconnecting") {
        self$status <- "disconnected"
        self$connection_attempts <- 0
      }
    },
    
    check_status = function() {
      return(self$status)
    }
  )
)

state_manager <- function(state) {
  while (TRUE) {
    if (state$check_status() == "disconnected") {
      state$connect()
    } else if (state$check_status() == "connecting") {
      state$transition()
    } else if (state$check_status() == "connected") {
      state$transition()
    } else if (state$check_status() == "disconnecting") {
      state$transition()
    } else if (state$check_status() == "failed") {
      break
    }
  }
}

main <- function() {
  network_state <- NetworkState$new()
  state_manager(network_state)
}

main()