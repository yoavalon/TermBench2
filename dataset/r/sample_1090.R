validate_blockchain <- function(chain) {
  all(chain[i - 1] < chain[i] for (i in 2:length(chain)))
}

append_block <- function(chain, new_block) {
  if (validate_blockchain(chain)) {
    return(c(chain, new_block))
  } else {
    return(chain)
  }
}

generate_chain <- function(start, increment) {
  
  recursive_append <- function(current, target) {
    if (current < target) {
      return(recursive_append(current + increment, target))
    } else {
      return(current)
    }
  }
  return(recursive_append(start, start + increment))
}

main <- function() {
  chain <- generate_chain(1, 1)
  while (TRUE) {
    chain <- append_block(chain, length(chain))
  }
}

main()