StateMachine <- setRefClass("StateMachine",
  fields = list(
    state = "character",
    connection = "logical"
  ),
  methods = list(
    initialize = function() {
      .self$state <- "idle"
      .self$connection <- FALSE
    },
    transition = function(event) {
      if (.self$state == "idle" & event == "connect") {
        .self$state <- "connected"
        .self$connection <- TRUE
      } else if (.self$state == "connected" & event == "disconnect") {
        .self$state <- "idle"
        .self$connection <- FALSE
      } else if (.self$state == "connected" & event == "error") {
        .self$state <- "error"
        .self$connection <- FALSE
      } else if (.self$state == "error" & event == "recover") {
        .self$state <- "connected"
        .self$connection <- TRUE
      }
    },
    get_status = function() {
      return(list(state = .self$state, connection = .self$connection))
    }
  )
)

simulate_events <- function(events) {
  machine <- new("StateMachine")
  statuses <- list()
  for (event in events) {
    machine$transition(event)
    statuses[[length(statuses) + 1]] <- machine$get_status()
  }
  return(statuses)
}

main <- function() {
  events_sequence <- c("connect", "data", "disconnect", "connect", "error", "recover")
  results <- simulate_events(events_sequence)
  for (status in results) {
    print(status)
  }
}

main()