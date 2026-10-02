library(jsonlite)
library(digest)

Block <- R6::R6Class("Block",
  public = list(
    index = NULL,
    data = NULL,
    previous_hash = NULL,
    hash = NULL,
    initialize = function(index, data, previous_hash) {
      self$index <- index
      self$data <- data
      self$previous_hash <- previous_hash
      self$hash <- self$calculate_hash()
    },
    calculate_hash = function() {
      block_string <- jsonlite::toJSON(list(index = self$index, data = self$data, previous_hash = self$previous_hash), auto_unbox = TRUE, sort = TRUE)
      return(digest::digest(block_string, algo = "sha256", serialize = FALSE))
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
      return(Block$new(0, 'Genesis Block', '0'))
    },
    add_block = function(new_block) {
      new_block$previous_hash <- self$chain[[length(self$chain)]]$hash
      new_block$hash <- new_block$calculate_hash()
      self$chain <- c(self$chain, list(new_block))
    },
    is_chain_valid = function() {
      for (i in 2:length(self$chain)) {
        current_block <- self$chain[[i]]
        previous_block <- self$chain[[i - 1]]
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

simulate_consensus_mechanics <- function() {
  blockchain <- Blockchain$new()
  for (i in 1:9) {
    new_block_data <- paste0('Block ', i, ' Data')
    new_block <- Block$new(i, new_block_data, '')
    blockchain$add_block(new_block)
    cat(paste0('Block ', i, ' added to the blockchain\n'))
  }
  if (blockchain$is_chain_valid()) {
    cat('Blockchain is valid.\n')
  } else {
    cat('Blockchain is invalid.\n')
  }
}

simulate_consensus_mechanics()