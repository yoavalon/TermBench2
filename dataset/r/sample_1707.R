ConnectionState <- setRefClass("ConnectionState",
  fields = list(
    state = "character",
    states = "character"
  ),
  methods = list(
    initialize = function() {
      .self$state <- "DISCONNECTED"
      .self$states <- c("DISCONNECTED", "CONNECTING", "CONNECTED", "DISCONNECTING")
    },
    transition = function(event) {
      if (.self$state == "DISCONNECTED" & event == "CONNECT") {
        .self$state <- "CONNECTING"
      } else if (.self$state == "CONNECTING") {
        .self$state <- "CONNECTED"
      } else if (.self$state == "CONNECTED" & event == "DISCONNECT") {
        .self$state <- "DISCONNECTING"
      } else if (.self$state == "DISCONNECTING") {
        .self$state <- "DISCONNECTED"
      }
    },
    currentState = function() {
      return(.self$state)
    }
  )
)

EventGenerator <- setRefClass("EventGenerator",
  fields = list(
    events = "character",
    index = "numeric"
  ),
  methods = list(
    initialize = function() {
      .self$events <- c("CONNECT", "DISCONNECT")
      .self$index <- 0
    },
    nextEvent = function() {
      event <- .self$events[.self$index + 1]
      .self$index <- (.self$index + 1) %% length(.self$events)
      return(event)
    }
  )
)

NetworkSimulator <- setRefClass("NetworkSimulator",
  fields = list(
    stateMachine = "ConnectionState",
    eventGenerator = "EventGenerator"
  ),
  methods = list(
    initialize = function() {
      .self$stateMachine <- ConnectionState$new()
      .self$eventGenerator <- EventGenerator$new()
    },
    simulate = function() {
      while (TRUE) {
        event <- .self$eventGenerator$nextEvent()
        .self$stateMachine$transition(event)
        print(.self$stateMachine$currentState())
      }
    }
  )
)

main <- function() {
  simulator <- NetworkSimulator$new()
  simulator$simulate()
}

main()