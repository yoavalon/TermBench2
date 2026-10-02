NetworkState <- setRefClass("NetworkState",
  fields = list(
    state = "character",
    connection = "logical"
  ),
  methods = list(
    initialize = function() {
      state <<- "idle"
      connection <<- NA
    },
    transition = function(event) {
      if (state == "idle" && event == "connect") {
        state <<- "connected"
        connection <<- TRUE
      } else if (state == "connected" && event == "disconnect") {
        state <<- "idle"
        connection <<- FALSE
      } else if (state == "idle" && event == "error") {
        state <<- "error"
      } else if (state == "connected" && event == "error") {
        state <<- "error"
      } else if (state == "error" && event == "recover") {
        state <<- "idle"
      }
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
      events <<- c("connect", "disconnect", "error", "recover")
      index <<- 1
    },
    next_event = function() {
      event <- events[index]
      index <<- (index %% length(events)) + 1
      return(event)
    }
  )
)

NetworkSystem <- setRefClass("NetworkSystem",
  fields = list(
    state_machine = "NetworkState",
    event_source = "EventGenerator"
  ),
  methods = list(
    initialize = function() {
      state_machine <<- new("NetworkState")
      event_source <<- new("EventGenerator")
    },
    run = function() {
      while (TRUE) {
        event <- event_source$next_event()
        state_machine$transition(event)
        cat("Event:", event, "State:", state_machine$state, "\n")
      }
    }
  )
)

main <- function() {
  system <- new("NetworkSystem")
  system$run()
}

main()