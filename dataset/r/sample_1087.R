StateMachine <- setRefClass("StateMachine",
  fields = list(state = "character"),
  methods = list(
    initialize = function() {
      .self$state <- "idle"
    },
    transition = function() {
      if (.self$state == "idle") {
        .self$state <<- "connecting"
      } else if (.self$state == "connecting") {
        .self$state <<- "connected"
      } else if (.self$state == "connected") {
        .self$state <<- "disconnected"
      } else {
        .self$state <<- "idle"
      }
    }
  )
)

recursive_function <- function(sm) {
  sm$transition()
  recursive_function(sm)
}

main <- function() {
  sm <- new("StateMachine")
  recursive_function(sm)
}

main()