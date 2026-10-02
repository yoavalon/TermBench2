NetworkState <- setRefClass("NetworkState",
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
                .self$state <<- "idle"
            } else {
                .self$state <<- "error"
            }
        }
    )
)

NetworkManager <- setRefClass("NetworkManager",
    fields = list(state_machine = "NetworkState"),
    methods = list(
        initialize = function() {
            .self$state_machine <- NetworkState$new()
        },
        process_events = function(events) {
            for (event in events) {
                .self$state_machine$transition(event)
                if (.self$state_machine$state == "error") {
                    return(FALSE)
                }
            }
            return(TRUE)
        }
    )
)

EventGenerator <- setRefClass("EventGenerator",
    fields = list(events = "character"),
    methods = list(
        initialize = function() {
            .self$events <- c("connect", "data", "disconnect")
        },
        generate = function() {
            return(.self$events)
        }
    )
)

main <- function() {
    event_gen <- EventGenerator$new()
    network_mgr <- NetworkManager$new()
    events <- event_gen$generate()
    success <- network_mgr$process_events(events)
    print(success)
}

main()