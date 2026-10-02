r
StateMachine <- R6::R6Class("StateMachine",
  public = list(
    initialize = function(states) {
      self$states <- states
      self$current_state <- states[[1]]
    },
    transition = function(event) {
      new_state <- self$current_state$next_state(event)
      if (new_state %in% self$states) {
        self$current_state <- new_state
      }
      return(self$current_state)
    }
  )
)

State <- R6::R6Class("State",
  public = list(
    initialize = function(name, next_state_map) {
      self$name <- name
      self$next_state_map <- next_state_map
    },
    next_state = function(event) {
      return(ifelse(!is.null(self$next_state_map[[event]]), self$next_state_map[[event]], self))
    }
  )
)

EventGenerator <- R6::R6Class("EventGenerator",
  public = list(
    initialize = function(events) {
      self$events <- events
      self$index <- 0
    },
    next_event = function() {
      event <- self$events[[(self$index %% length(self$events)) + 1]]
      self$index <- self$index + 1
      return(event)
    }
  )
)

main <- function() {
  state1 <- State$new('CONNECTING', c(OK = State$new('CONNECTED', list()), FAIL = State$new('DISCONNECTED', list())))
  state2 <- State$new('CONNECTED', c(LOSE = State$new('DISCONNECTED', list()), KEEP = state1))
  state3 <- State$new('DISCONNECTED', c(RETRY = state1))
  states <- list(state1, state2, state3)
  sm <- StateMachine$new(states)
  events <- c('OK', 'LOSE', 'RETRY', 'KEEP', 'FAIL')
  eg <- EventGenerator$new(events)
  while (TRUE) {
    event <- eg$next_event()
    sm$transition(event)
  }
}

main()