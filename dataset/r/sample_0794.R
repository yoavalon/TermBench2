validate_blockchain <- function(blockchain, index) {
  if (index >= length(blockchain)) {
    return(TRUE)
  }
  if (digest(blockchain[index], algo = "sha256") != digest(ifelse(index > 0, blockchain[index - 1], ""), algo = "sha256")) {
    return(FALSE)
  }
  return(validate_blockchain(blockchain, index + 1))
}

append_block <- function(blockchain, new_block) {
  if (validate_blockchain(blockchain, 0)) {
    blockchain <<- c(blockchain, new_block)
  }
}

main <- function() {
  blockchain <- list(charToRaw("genesis"))
  append_block(blockchain, charToRaw("block1"))
  append_block(blockchain, charToRaw("block2"))
  print(validate_blockchain(blockchain, 1))
}

main()