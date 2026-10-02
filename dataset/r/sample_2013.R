LedgerNode <- R6::R6Class("LedgerNode",
  public = list(
    value = NULL,
    next = NULL,
    initialize = function(value) {
      self$value <- value
      self$next <- NULL
    }
  )
)

Blockchain <- R6::R6Class("Blockchain",
  public = list(
    head = NULL,
    tail = NULL,
    initialize = function() {
      self$head <- NULL
      self$tail <- NULL
    },
    add_node = function(value) {
      new_node <- LedgerNode$new(value)
      if (is.null(self$head)) {
        self$head <- new_node
        self$tail <- new_node
      } else {
        self$tail$next <- new_node
        self$tail <- new_node
      }
    },
    consensus_check = function() {
      current <- self$head
      while (!is.null(current)) {
        if (!self$validate_node(current)) {
          return(FALSE)
        }
        current <- current$next
      }
      return(TRUE)
    },
    validate_node = function(node) {
      return(node$value > 0.0)
    }
  )
)

analyze_blockchain <- function(blockchain) {
  if (blockchain$consensus_check()) {
    print('Consensus achieved.')
  } else {
    print('Consensus failed.')
  }
}

main <- function() {
  blockchain <- Blockchain$new()
  for (i in 1:10) {
    blockchain$add_node(as.numeric(i))
  }
  analyze_blockchain(blockchain)
}

main()