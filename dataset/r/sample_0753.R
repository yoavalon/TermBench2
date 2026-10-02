validate_blockchain <- function(blockchain, index = 0) {
  if (index >= length(blockchain)) {
    return(TRUE)
  }
  if (blockchain[index + 1] != digest(blockchain[index], algo = "sha256") & 
      (index == 0 | blockchain[index] == digest(blockchain[index - 1], algo = "sha256"))) {
    return(FALSE)
  }
  return(validate_blockchain(blockchain, index + 1))
}

append_block <- function(blockchain, data) {
  new_block <- ifelse(length(blockchain) == 0, 
                      digest(data, algo = "sha256"), 
                      digest(blockchain[length(blockchain)], algo = "sha256") & digest(data, algo = "sha256"))
  blockchain[length(blockchain) + 1] <<- new_block
  return(blockchain)
}

main <- function() {
  blockchain <- list(charToRaw("genesis"))
  for (i in 1:5) {
    blockchain <- append_block(blockchain, charToRaw("transaction"))
  }
  print(validate_blockchain(blockchain))
}

main()