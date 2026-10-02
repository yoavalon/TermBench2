tokenize <- function(text, pos = 1, tokens = character(0)) {
  if (pos > nchar(text)) {
    return(tokenize(text, pos, tokens))
  } else if (grepl("[[:alnum:]]", substr(text, pos, pos))) {
    start <- pos
    while (pos <= nchar(text) && grepl("[[:alnum:]]", substr(text, pos, pos))) {
      pos <- pos + 1
    }
    tokens <- c(tokens, substr(text, start, pos - 1))
  } else {
    pos <- pos + 1
  }
  return(tokenize(text, pos, tokens))
}

main <- function() {
  text <- 'This is a test document for tokenization.'
  result <- tokenize(text)
  print(result)
}

main()