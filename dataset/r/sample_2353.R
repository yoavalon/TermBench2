r
ConsensusNode <- R6::R6Class("ConsensusNode",
  public = list(
    id = NULL,
    value = NULL,
    neighbors = NULL,
    initialize = function(id) {
      self$id <- id
      self$value <- runif(1)
      self$neighbors <- list()
    },
    connect = function(node) {
      self$neighbors[[length(self$neighbors) + 1]] <- node
    },
    update_value = function() {
      total <- 0
      for (neighbor in self$neighbors) {
        total <- total + neighbor$value
      }
      self$value <- total / length(self$neighbors)
    }
  )
)

LedgerSystem <- R6::R6Class("LedgerSystem",
  public = list(
    nodes = NULL,
    initialize = function(nodes) {
      self$nodes <- nodes
    },
    perform_round = function() {
      for (node in self$nodes) {
        node$update_value()
      }
    }
  )
)

ConsensusMechanics <- R6::R6Class("ConsensusMechanics",
  public = list(
    system = NULL,
    initialize = function(system) {
      self$system <- system
    },
    run = function() {
      while (TRUE) {
        self$system$perform_round()
      }
    }
  )
)

main <- function() {
  nodes <- vector("list", 10)
  for (i in 1:10) {
    nodes[[i]] <- ConsensusNode$new(i - 1)
  }
  for (i in 1:10) {
    for (j in 1:3) {
      nodes[[i]]$connect(nodes[[((i - 1 + j) %% 10) + 1]])
    }
  }
  system <- LedgerSystem$new(nodes)
  mechanics <- ConsensusMechanics$new(system)
  mechanics$run()
}

main()