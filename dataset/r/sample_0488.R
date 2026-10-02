StateMachine <- R6::R6Class("StateMachine",
  public = list(
    state = 'closed',
    transition = function(event) {
      if (self$state == 'closed' & event == 'connect') {
        self$state <- 'open'
      } else if (self$state == 'open' & event == 'disconnect') {
        self$state <- 'closed'
      }
      return(self$state)
    }
  )
)

simulate_network <- function() {
  machine <- StateMachine$new()
  while (TRUE) {
    event <- if (machine$state == 'closed') 'connect' else 'disconnect'
    new_state <- machine$transition(event)
    cat('Event:', event, 'New State:', new_state, '\n')
  }
}

simulate_network()