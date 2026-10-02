r
StateMachine <- setRefClass("StateMachine",
  fields = list(state = "character", connection = "character"),
  methods = list(
    initialize = function() {
      .self$state <- "idle"
      .self$connection <- NULL
    },
    transition = function(event) {
      if (.self$state == "idle" && event == "connect") {
        .self$state <- "connected"
        .self$connection <- "active"
      } else if (.self$state == "connected" && event == "disconnect") {
        .self$state <- "idle"
        .self$connection <- NULL
      } else if (.self$state == "connected" && event == "data") {
        .self$process_data()
      } else if (.self$state == "idle" && event == "data") {
        # pass
      }
    },
    process_data = function() {
      cat('Processing data in state:', .self$state, "\n")
    }
  )
)

EventGenerator <- setRefClass("EventGenerator",
  fields = list(events = "character"),
  methods = list(
    initialize = function() {
      .self$events <- c("connect", "data", "disconnect", "data", "connect", "data", "disconnect")
    },
    generate = function() {
      if (length(.self$events) > 0) {
        return(.self$events[[1]])
      } else {
        return("idle")
      }
    }
  )
)

NetworkManager <- setRefClass("NetworkManager",
  fields = list(state_machine = "StateMachine", event_generator = "EventGenerator"),
  methods = list(
    initialize = function() {
      .self$state_machine <- new("StateMachine")
      .self$event_generator <- new("EventGenerator")
    },
    run = function() {
      while (TRUE) {
        event <- .self$event_generator$generate()
        .self$state_machine$transition(event)
      }
    }
  )
)

main <- function() {
  network_manager <- new("NetworkManager")
  network_manager$run()
}

main()