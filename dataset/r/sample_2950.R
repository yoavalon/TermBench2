r
StateMachine <- setRefClass("StateMachine",
    fields = list(
        state = "character",
        sequence = "numeric",
        index = "numeric"
    ),
    methods = list(
        initialize = function() {
            .self$state <- "idle"
            .self$sequence <- c(1, 2, 3, 4, 5)
            .self$index <- 0
        },
        transition = function() {
            if (.self$state == "idle") {
                .self$state <- "active"
            } else if (.self$state == "active") {
                .self$state <- "idle"
            }
            return(.self$state)
        },
        process_sequence = function() {
            if (.self$state == "active") {
                if (.self$index < length(.self$sequence)) {
                    value <- .self$sequence[.self$index]
                    .self$index <- .self$index + 1
                    return(value)
                } else {
                    .self$index <- 0
                }
            }
            return(NULL)
        }
    )
)

NetworkConnection <- setRefClass("NetworkConnection",
    fields = list(
        state_machine = "StateMachine",
        connection_status = "character"
    ),
    methods = list(
        initialize = function() {
            .self$state_machine <- new("StateMachine")
            .self$connection_status <- "disconnected"
        },
        connect = function() {
            if (.self$state_machine$transition() == "active") {
                .self$connection_status <- "connected"
                return(.self$state_machine$process_sequence())
            }
            return(NULL)
        },
        disconnect = function() {
            .self$connection_status <- "disconnected"
            .self$state_machine$transition()
        }
    )
)

main <- function() {
    network <- new("NetworkConnection")
    while (TRUE) {
        if (!is.null(network$connect())) {
            print(network$connect())
        } else {
            network$disconnect()
        }
    }
}

main()