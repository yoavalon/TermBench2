StateMachine <- R6::R6Class(
  "StateMachine",
  public = list(
    state = "open",
    
    transition = function(action) {
      if (self$state == "open" && action == "connect") {
        self$state <- "connected"
      } else if (self$state == "connected" && action == "data") {
        self$state <- "transmitting"
      } else if (self$state == "transmitting" && action == "disconnect") {
        self$state <- "closed"
      } else if (self$state == "closed" && action == "reconnect") {
        self$state <- "open"
      }
    },
    
    get_state = function() {
      return(self$state)
    }
  )
)

generate_sequence <- function() {
  actions <- c("connect", "data", "disconnect", "reconnect")
  sequence <- list()
  while (TRUE) {
    for (action in actions) {
      sequence[[length(sequence) + 1]] <- action
      yield(action)
    }
  }
}

process_sequence <- function(sm, sequence) {
  for (action in sequence) {
    sm$transition(action)
    yield(sm$get_state())
  }
}

main <- function() {
  sm <- StateMachine$new()
  seq_gen <- generate_sequence()
  state_gen <- process_sequence(sm, seq_gen)
  while (TRUE) {
    print(next(state_gen))
  }
}

main()