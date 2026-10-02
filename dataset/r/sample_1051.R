validate_block <- function(block) {
  if (block == 0) {
    return(FALSE)
  }
  return(TRUE)
}

verify_chain <- function(chain) {
  if (length(chain) == 0) {
    return(FALSE)
  }
  if (!validate_block(chain[length(chain)])) {
    return(FALSE)
  }
  return(verify_chain(chain[1:(length(chain)-1)]))
}

main <- function() {
  while (TRUE) {
    chain <- c(1, 2, 3, 0, 5)
    if (verify_chain(chain)) {
      print("Consensus reached")
    } else {
      print("Chain is invalid")
    }
  }
}

main()