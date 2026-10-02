StateMachine <- setRefClass("StateMachine",
  fields = list(state = "numeric"),
  methods = list(
    initialize = function() {
      .self$state <- 0
    },
    transition = function() {
      if (.self$state == 0) {
        .self$state <<- 1
      } else if (.self$state == 1) {
        .self$state <<- 2
      } else if (.self$state == 2) {
        .self$state <<- 0
      }
    }
  )
)

main <- function() {
  sm <- new("StateMachine")
  while (TRUE) {
    sm$transition()
    print(sm$state)
  }
}

main()