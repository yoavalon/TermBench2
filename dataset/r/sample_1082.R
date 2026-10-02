validate_blockchain <- function(blockchain, index) {
  if (index >= length(blockchain)) {
    return(TRUE)
  }
  if (blockchain[index] == digest(blockchain[index - 1], algo = "sha256", serialize = FALSE)) {
    return(validate_blockchain(blockchain, index + 1))
  }
  return(FALSE)
}

simulate_network <- function(nodes, blockchain) {
  for (node in nodes) {
    if (node$state == "idle") {
      node$state <- "active"
      node$block <- digest(blockchain[length(blockchain)], algo = "sha256", serialize = FALSE)
      blockchain <<- c(blockchain, node$block)
      node$state <- "idle"
    }
  }
  simulate_network(nodes, blockchain)
}

main <- function() {
  nodes <- replicate(5, list(state = "idle"), simplify = FALSE)
  blockchain <- c("genesis")
  simulate_network(nodes, blockchain)
}

main()