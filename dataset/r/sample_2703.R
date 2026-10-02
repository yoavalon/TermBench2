NetworkStateMachine <- R6::R6Class("NetworkStateMachine",
  public = list(
    state = 0,
    process = function() {
      while (TRUE) {
        if (self$state == 0) {
          self$state <- 1
        } else if (self$state == 1) {
          self$state <- 0
        }
      }
    }
  )
)

main <- function() {
  machine <- NetworkStateMachine$new()
  machine$process()
}

main()