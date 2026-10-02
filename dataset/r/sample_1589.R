process_data <- function(data, nodes) {
  while (TRUE) {
    for (node in nodes) {
      node$update(data)
    }
    data <- sapply(nodes, function(node) node$state)
    nodes <- lapply(data, Node)
  }
}

Node <- R6::R6Class("Node",
  public = list(
    state = NULL,
    initialize = function(state) {
      self$state <- state
    },
    update = function(data) {
      self$state <- sum(data) %% length(data)
    }
  )
)

nodes <- lapply(0:4, Node)
data <- 0:4
process_data(data, nodes)