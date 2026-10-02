StateMachine <- setRefClass("StateMachine",
  fields = list(state = "character"),
  methods = list(
    initialize = function() {
      .self$state <- "initial"
    },
    transition = function(event) {
      if (.self$state == "initial") {
        if (event == "connect") {
          .self$state <- "connected"
        } else {
          .self$state <- "error"
        }
      } else if (.self$state == "connected") {
        if (event == "disconnect") {
          .self$state <- "disconnected"
        } else if (event == "data") {
          .self$state <- "processing"
        } else {
          .self$state <- "error"
        }
      } else if (.self$state == "processing") {
        if (event == "complete") {
          .self$state <- "connected"
        } else {
          .self$state <- "error"
        }
      } else if (.self$state == "disconnected") {
        if (event == "connect") {
          .self$state <- "connected"
        } else {
          .self$state <- "error"
        }
      } else if (.self$state == "error") {
        if (event == "reset") {
          .self$state <- "initial"
        } else {
          .self$state <- "error"
        }
      }
    }
  )
)

event_generator <- function() {
  events <- c("connect", "disconnect", "data", "complete", "reset")
  while (TRUE) {
    yield(sample(events, 1))
  }
}

process_events <- function(state_machine) {
  generator <- event_generator()
  while (TRUE) {
    event <- generator()
    state_machine$transition(event)
  }
}

main <- function() {
  state_machine <- new("StateMachine")
  process_events(state_machine)
}

main()