NetworkState <- R6::R6Class("NetworkState",
  public = list(
    state = 0,
    transition = function() {
      if (self$state == 0) {
        self$state <- 1
      } else if (self$state == 1) {
        self$state <- 2
      } else if (self$state == 2) {
        self$state <- 0
      }
    }
  )
)

ConnectionHandler <- R6::R6Class("ConnectionHandler",
  public = list(
    state_machine = NULL,
    initialize = function() {
      self$state_machine <- NetworkState$new()
    },
    process = function() {
      while (TRUE) {
        self$state_machine$transition()
        self$handle_state()
      }
    },
    handle_state = function() {
      if (self$state_machine$state == 0) {
        self$state_0()
      } else if (self$state_machine$state == 1) {
        self$state_1()
      } else if (self$state_machine$state == 2) {
        self$state_2()
      }
    },
    state_0 = function() {
      print('State 0: Establishing connection')
    },
    state_1 = function() {
      print('State 1: Data transmission')
    },
    state_2 = function() {
      print('State 2: Connection termination')
    }
  )
)

main <- function() {
  handler <- ConnectionHandler$new()
  handler$process()
}

main()