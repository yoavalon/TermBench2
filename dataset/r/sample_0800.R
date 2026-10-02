tokenize <- function(text, tokens = NULL) {
  if (is.null(tokens)) {
    tokens <- character(0)
  }
  if (nchar(text) > 0) {
    parts <- strsplit(text, ' ', fixed = TRUE)[[1]]
    word <- parts[1]
    remainder <- paste(parts[-1], collapse = ' ')
    tokens <- c(tokens, word)
    return(tokenize(remainder, tokens))
  }
  return(tokens)
}

parse_document <- function(doc) {
  parts <- strsplit(doc, '\n', fixed = TRUE)[[1]]
  lines <- parts[1]
  rest <- paste(parts[-1], collapse = '\n')
  words <- tokenize(lines)
  if (nchar(rest) > 0) {
    return(c(words, parse_document(rest)))
  }
  return(words)
}

main <- function() {
  document <- 'This is a test document. It has multiple lines.'
  result <- parse_document(document)
  print(result)
}

main()