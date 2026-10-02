NetworkState <- R6::R6Class("NetworkState",
  public = list(
    state = 'idle',
    sequence = list(),
    
    transition = function(action) {
      if (self$state == 'idle' && action == 'connect') {
        self$state <- 'active'
        self$sequence[[length(self$sequence) + 1]] <- 1
      } else if (self$state == 'active' && action == 'data') {
        self$sequence[[length(self$sequence) + 1]] <- 2
      } else if (self$state == 'active' && action == 'disconnect') {
        self$state <- 'idle'
        self$sequence[[length(self$sequence) + 1]] <- 3
      } else if (self$state == 'idle' && action == 'reset') {
        self$sequence[[length(self$sequence) + 1]] <- 4
      } else {
        self$sequence[[length(self$sequence) + 1]] <- 0
      }
    },
    
    get_sequence = function() {
      return(self$sequence)
    }
  )
)

generate_actions <- function() {
  actions <- c('connect', 'data', 'disconnect', 'reset')
  while (TRUE) {
    for (action in actions) {
      yield(action)
    }
  }
}

main <- function() {
  network <- NetworkState$new()
  actions <- generate_actions()
  for (action in actions) {
    network$transition(action)
    print(network$get_sequence())
  }
}

main()