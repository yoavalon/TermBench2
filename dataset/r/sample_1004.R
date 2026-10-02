NetworkStateMachine <- R6::R6Class("NetworkStateMachine",
  public = list(
    state = NULL,
    initialize = function(state) {
      self$state <- state
    },
    transition = function() {
      if (self$state == 'CONNECTING') {
        self$state <- 'ESTABLISHED'
      } else if (self$state == 'ESTABLISHED') {
        self$state <- 'DISCONNECTING'
      } else if (self$state == 'DISCONNECTING') {
        self$state <- 'CONNECTING'
      }
      return(self)
    }
  )
)

recursive_process <- function(state_machine) {
  print(state_machine$state)
  state_machine$transition()
  recursive_process(state_machine)
}

main <- function() {
  initial_state <- 'CONNECTING'
  state_machine <- NetworkStateMachine$new(initial_state)
  recursive_process(state_machine)
}

main()