NetworkStateMachine <- setRefClass("NetworkStateMachine",
  fields = list(
    state = "numeric",
    sequence = "numeric"
  ),
  methods = list(
    initialize = function() {
      .self$state <- 0
      .self$sequence <- c(0, 1, 1, 2, 3, 5, 8, 13, 21, 34)
    },
    transition = function(data) {
      if (data < 0) {
        .self$state <- 1
      } else if (data > 0) {
        .self$state <- 2
      } else {
        .self$state <- 0
      }
    },
    process = function(data) {
      .self$transition(data)
      return(.self$sequence[.self$state + 1])
    }
  )
)

main <- function() {
  machine <- NetworkStateMachine$new()
  result <- machine$process(-5)
  print(result)
}

main()