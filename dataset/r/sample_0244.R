NetworkState <- setRefClass(
  "NetworkState",
  fields = list(state = "character"),
  methods = list(
    initialize = function() {
      .self$state <<- "init"
    },
    transition = function(event) {
      if (.self$state == "init" && event == "connect") {
        .self$state <<- "connected"
      } else if (.self$state == "connected" && event == "disconnect") {
        .self$state <<- "disconnected"
      } else if (.self$state == "disconnected" && event == "reconnect") {
        .self$state <<- "connected"
      }
    }
  )
)

EventProcessor <- setRefClass(
  "EventProcessor",
  fields = list(
    state_machine = "NetworkState",
    events = "character"
  ),
  methods = list(
    initialize = function(state_machine) {
      .self$state_machine <<- state_machine
      .self$events <<- character()
    },
    add_event = function(event) {
      .self$events <<- c(.self$events, event)
    },
    process_events = function() {
      for (event in .self$events) {
        .self$state_machine$transition(event)
      }
      .self$events <<- character()
    }
  )
)

main <- function() {
  state_machine <- NetworkState$new()
  processor <- EventProcessor$new(state_machine)
  processor$add_event("connect")
  processor$process_events()
  processor$add_event("disconnect")
  processor$process_events()
  processor$add_event("reconnect")
  processor$process_events()
  print(state_machine$state)
}

main()