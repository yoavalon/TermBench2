ConnectionState <- setRefClass("ConnectionState",
  fields = list(state = "character", data_buffer = "list"),
  methods = list(
    initialize = function() {
      .self$state <<- 'DISCONNECTED'
      .self$data_buffer <<- list()
    },
    transition = function(event) {
      if (.self$state == 'DISCONNECTED' & event == 'CONNECT') {
        .self$state <<- 'CONNECTED'
      } else if (.self$state == 'CONNECTED' & event == 'SEND') {
        .self$state <<- 'SENDING'
      } else if (.self$state == 'SENDING' & event == 'ACKNOWLEDGE') {
        .self$state <<- 'ACKNOWLEDGED'
      } else if (.self$state == 'ACKNOWLEDGED' & event == 'DISCONNECT') {
        .self$state <<- 'DISCONNECTED'
      } else if (.self$state == 'CONNECTED' & event == 'DATA') {
        .self$data_buffer <<- c(.self$data_buffer, event)
      } else if (.self$state == 'SENDING' & event == 'REJECT') {
        .self$state <<- 'REJECTED'
      } else if (.self$state == 'REJECTED' & event == 'RETRY') {
        .self$state <<- 'SENDING'
      }
      return(.self$state)
    }
  )
)

NetworkHandler <- setRefClass("NetworkHandler",
  fields = list(connection = "ConnectionState"),
  methods = list(
    initialize = function() {
      .self$connection <<- ConnectionState$new()
    },
    process_event = function(event) {
      new_state <<- .self$connection$transition(event)
      return(new_state)
    }
  )
)

EventSimulator <- setRefClass("EventSimulator",
  fields = list(events = "character"),
  methods = list(
    initialize = function() {
      .self$events <<- c('CONNECT', 'DATA', 'SEND', 'ACKNOWLEDGE', 'DISCONNECT')
    },
    generate_events = function() {
      return(.self$events)
    }
  )
)

main <- function() {
  handler <<- NetworkHandler$new()
  simulator <<- EventSimulator$new()
  for (event in simulator$generate_events()) {
    state <<- handler$process_event(event)
    cat('Event:', event, ', New State:', state, '\n')
  }
}

main()