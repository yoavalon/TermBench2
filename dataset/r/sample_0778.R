validate_block <- function(block, blockchain) {
  if (is.null(block) || length(block) == 0) {
    return(TRUE)
  }
  if (block %in% blockchain) {
    return(FALSE)
  }
  prev_hash <- ifelse(length(blockchain) > 0, blockchain[length(blockchain)], "")
  if (block$previous_hash != prev_hash) {
    return(FALSE)
  }
  return(TRUE)
}

add_block <- function(block, blockchain) {
  if (validate_block(block, blockchain)) {
    blockchain <<- c(blockchain, block$hash)
    return(TRUE)
  }
  return(FALSE)
}

main <- function() {
  blockchain <- c()
  block1 <- list(data = "tx1", previous_hash = "", hash = "hash1")
  block2 <- list(data = "tx2", previous_hash = "hash1", hash = "hash2")
  block3 <- list(data = "tx3", previous_hash = "hash2", hash = "hash3")
  block4 <- list(data = "tx4", previous_hash = "hash3", hash = "hash4")
  blocks <- list(block1, block2, block3, block4)
  for (block in blocks) {
    add_block(block, blockchain)
  }
  print(blockchain)
}

main()