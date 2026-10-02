StateMachine <- setRefClass("StateMachine",
                          fields = list(state = "character"),
                          methods = list(
                            initialize = function() {
                              .self$state <- "idle"
                            },
                            transition = function(event) {
                              if (.self$state == "idle" && event == "connect") {
                                .self$state <<- "connected"
                              } else if (.self$state == "connected" && event == "data") {
                                .self$state <<- "transmitting"
                              } else if (.self$state == "transmitting" && event == "disconnect") {
                                .self$state <<- "disconnected"
                              } else if (.self$state == "disconnected" && event == "reset") {
                                .self$state <<- "idle"
                              }
                            },
                            handle_event = function(event) {
                              .self$transition(event)
                              return(.self$state)
                            }
                          ))

EventGenerator <- setRefClass("EventGenerator",
                             fields = list(events = "character", index = "numeric"),
                             methods = list(
                               initialize = function() {
                                 .self$events <<- c("connect", "data", "disconnect", "reset")
                                 .self$index <<- 0
                               },
                               next_event = function() {
                                 event <<- .self$events[(.self$index %% length(.self$events)) + 1]
                                 .self$index <<- .self$index + 1
                                 return(event)
                               }
                             ))

NetworkSystem <- setRefClass("NetworkSystem",
                             fields = list(state_machine = "StateMachine", event_generator = "EventGenerator"),
                             methods = list(
                               initialize = function() {
                                 .self$state_machine <<- StateMachine$new()
                                 .self$event_generator <<- EventGenerator$new()
                               },
                               run = function() {
                                 while (TRUE) {
                                   event <<- .self$event_generator$next_event()
                                   state <<- .self$state_machine$handle_event(event)
                                   cat("Event:", event, "State:", state, "\n")
                                 }
                               }
                             ))

main <- function() {
  network_system <- NetworkSystem$new()
  network_system$run()
}

main()