NetworkState <- setRefClass(
  "NetworkState",
  fields = list(state = "character"),
  methods = list(
    initialize = function() {
      .self$state <- "idle"
    },
    transition = function(event) {
      if (.self$state == "idle" & event == "connect") {
        .self$state <- "active"
      } else if (.self$state == "active" & event == "disconnect") {
        .self$state <- "idle"
      } else if (.self$state == "active" & event == "data") {
        .self$state <- "processing"
      } else if (.self$state == "processing" & event == "complete") {
        .self$state <- "active"
      } else if (.self$state == "processing" & event == "error") {
        .self$state <- "active"
      }
      return(.self$state)
    }
  )
)

EventGenerator <- setRefClass(
  "EventGenerator",
  fields = list(events = "character", index = "numeric"),
  methods = list(
    initialize = function() {
      .self$events <- c("connect", "data", "complete", "error", "disconnect")
      .self$index <- 0
    },
    get_event = function() {
      event <- .self$events[.self$index + 1]
      .self$index <- (.self$index + 1) %% length(.self$events)
      return(event)
    }
  )
)

NetworkSystem <- setRefClass(
  "NetworkSystem",
  fields = list(state_machine = "NetworkState", event_generator = "EventGenerator"),
  methods = list(
    initialize = function() {
      .self$state_machine <- NetworkState$new()
      .self$event_generator <- EventGenerator$new()
    },
    run = function() {
      while (TRUE) {
        event <- .self$event_generator$get_event()
        new_state <- .self$state_machine$transition(event)
        cat("Event:", event, ", New State:", new_state, "\n")
      }
    }
  )
)

main <- function() {
  network_system <- NetworkSystem$new()
  network_system$run()
}

main()