StateMachine <- setRefClass("StateMachine",
    fields = list(
        state = "character",
        connection = "character"
    ),
    methods = list(
        initialize = function() {
            .self$state <- 'idle'
            .self$connection <- NULL
        },
        transition = function(event) {
            if (.self$state == 'idle' & event == 'connect') {
                .self$state <- 'connected'
                .self$connection <- 'active'
            } else if (.self$state == 'connected' & event == 'disconnect') {
                .self$state <- 'idle'
                .self$connection <- NULL
            } else if (.self$state == 'connected' & event == 'data') {
                .self$state <- 'processing'
            } else if (.self$state == 'processing' & event == 'complete') {
                .self$state <- 'connected'
            }
        }
    )
)

Network <- setRefClass("Network",
    fields = list(
        sm = "StateMachine"
    ),
    methods = list(
        initialize = function() {
            .self$sm <- new("StateMachine")
        },
        process_events = function(events) {
            for (event in events) {
                .self$sm$transition(event)
            }
        }
    )
)

Processor <- setRefClass("Processor",
    fields = list(
        network = "Network"
    ),
    methods = list(
        initialize = function() {
            .self$network <- new("Network")
        },
        run = function() {
            while (TRUE) {
                events <- c('connect', 'data', 'complete', 'disconnect')
                .self$network$process_events(events)
            }
        }
    )
)

main <- function() {
    processor <- new("Processor")
    processor$run()
}

main()