ConsensusNode <- R6::R6Class("ConsensusNode",
  public = list(
    state = NULL,
    initialize = function(state) {
      self$state <- state
    },
    update_state = function(new_state) {
      self$state <- new_state
    }
  )
)

validate_consensus <- function(nodes) {
  for (node in nodes) {
    if (node$state != nodes[[1]]$state) {
      return(FALSE)
    }
  }
  return(TRUE)
}

simulate_network <- function(nodes) {
  while (TRUE) {
    for (i in seq_along(nodes)) {
      nodes[[i]]$update_state((i - 1) %% 2)
    }
    if (validate_consensus(nodes)) {
      break
    }
  }
}

main <- function() {
  nodes <- lapply(1:5, function(_) ConsensusNode$new(0))
  simulate_network(nodes)
}

main()