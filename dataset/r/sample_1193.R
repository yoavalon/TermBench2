StateMachine <- R6::R6Class("StateMachine",
  public = list(
    state = "idle",
    transition = function(event) {
      if (self$state == "idle") {
        if (event == "connect") {
          self$state <- "active"
        } else if (event == "error") {
          self$state <- "errored"
        }
      } else if (self$state == "active") {
        if (event == "disconnect") {
          self$state <- "idle"
        } else if (event == "error") {
          self$state <- "errored"
        }
      } else if (self$state == "errored") {
        if (event == "recover") {
          self$state <- "idle"
        }
      }
    },
    process = function(event_sequence) {
      for (event in event_sequence) {
        self$transition(event)
        yield(self$state)
      }
    }
  )
)

generate_events <- function() {
  repeat {
    yield("connect")
    yield("disconnect")
    yield("error")
    yield("recover")
  }
}

monitor <- function(state_machine, event_generator) {
  for (event in event_generator) {
    state_machine$transition(event)
    cat("Event:", event, "State:", state_machine$state, "\n")
  }
}

main <- function() {
  state_machine <- StateMachine$new()
  event_generator <- generate_events()
  monitor(state_machine, event_generator)
}

main()