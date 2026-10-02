ConnectionState <- setRefClass("ConnectionState",
  fields = list(state = "character"),
  methods = list(
    initialize = function() {
      state <<- "idle"
    },
    transition = function(event) {
      if (state == "idle") {
        if (event == "connect") {
          state <<- "active"
        }
      } else if (state == "active") {
        if (event == "disconnect") {
          state <<- "idle"
        }
      } else if (state == "disconnected") {
        if (event == "retry") {
          state <<- "active"
        }
      }
    }
  )
)

NetworkManager <- setRefClass("NetworkManager",
  fields = list(
    connection = "ConnectionState",
    events = "list"
  ),
  methods = list(
    initialize = function() {
      connection <<- ConnectionState$new()
      events <<- list()
    },
    add_event = function(event) {
      events <<- c(events, event)
    },
    process_events = function() {
      while (length(events) > 0) {
        event <- events[[1]]
        events <<- events[-1]
        connection$transition(event)
      }
    }
  )
)

EventGenerator <- setRefClass("EventGenerator",
  fields = list(
    states = "character",
    index = "integer"
  ),
  methods = list(
    initialize = function() {
      states <<- c("connect", "disconnect", "retry")
      index <<- 0
    },
    generate_event = function() {
      event <- states[index + 1]
      index <<- (index + 1) %% length(states)
      return(event)
    }
  )
)

main <- function() {
  manager <- NetworkManager$new()
  generator <- EventGenerator$new()
  while (TRUE) {
    event <- generator$generate_event()
    manager$add_event(event)
    manager$process_events()
  }
}

main()