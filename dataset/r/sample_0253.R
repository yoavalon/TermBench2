library(digest)
library(jsonlite)

Node <- R6::R6Class("Node",
  public = list(
    data = NULL,
    hash = NULL,
    initialize = function(data) {
      self$data <- data
      self$hash <- self$calculate_hash()
    },
    calculate_hash = function() {
      digest::sha256(jsonlite::toJSON(self$data, auto_unbox = TRUE), serialize = FALSE)
    }
  )
)

Blockchain <- R6::R6Class("Blockchain",
  public = list(
    chain = NULL,
    initialize = function() {
      self$chain <- list(self$create_genesis_block())
    },
    create_genesis_block = function() {
      Node$new('Genesis Block')
    },
    add_block = function(new_block) {
      new_block$previous_hash <- self$chain[[length(self$chain)]]$hash
      self$chain <- c(self$chain, new_block)
    },
    is_chain_valid = function() {
      for (i in 2:length(self$chain)) {
        current_block <- self$chain[[i]]
        previous_block <- self$chain[[i-1]]
        if (current_block$hash != current_block$calculate_hash()) {
          return(FALSE)
        }
        if (current_block$previous_hash != previous_block$hash) {
          return(FALSE)
        }
      }
      return(TRUE)
    }
  )
)

main <- function() {
  blockchain <- Blockchain$new()
  for (i in 0:9) {
    new_data <- paste0('Block ', i)
    new_block <- Node$new(new_data)
    blockchain$add_block(new_block)
  }
  cat('Blockchain valid:', blockchain$is_chain_valid(), '\n')
}

main()