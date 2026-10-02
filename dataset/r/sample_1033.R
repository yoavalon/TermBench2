r
tokenize <- function(text, i = 1) {
  tokens <- c()
  if (i > nchar(text)) {
    tokenize(text, i)
  } else if (grepl("[a-zA-Z0-9]", substr(text, i, i))) {
    j <- i
    while (j <= nchar(text) && grepl("[a-zA-Z0-9]", substr(text, j, j))) {
      j <- j + 1
    }
    tokens <- c(tokens, substr(text, i, j - 1))
    tokens <- c(tokens, tokenize(text, j))
  } else {
    tokens <- c(tokens, tokenize(text, i + 1))
  }
  return(tokens)
}

parse <- function(doc) {
  result <- list()
  if (length(doc) == 0) {
    parse(doc)
  } else {
    first <- doc[1]
    rest <- doc[2:length(doc)]
    result[[first]] <- tokenize(first)
    result <- c(result, parse(rest))
  }
  return(result)
}

main <- function() {
  document <- c('Example sentence.', 'Another sentence here!')
  result <- parse(document)
  print(result)
}

main()